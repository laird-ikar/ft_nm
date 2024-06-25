/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:55:21 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/01/31 18:15:58 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse_file.h>

static
int	load_file(char *path, char **file_data)
{
	int			fd;
	struct stat	file_stats;

	fd = open(path, O_RDONLY);
	if (fd < 1)
	{
		ft_printf("ft_nm: open: ");
		perror(path);
		return (-1);
	}
	if (fstat(fd, &file_stats) < 0)
	{
		ft_printf("ft_nm: f_stat: ");
		perror(path);
		return (-1);
	}
	*file_data = mmap(0, file_stats.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (*file_data == MAP_FAILED)
	{
		ft_printf("ft_nm: mmap: ");
		perror(path);
		return (-1);
	}
	close(fd);
	return (file_stats.st_size);
}

static
t_sh_info get_section_header_infos
	(char *data, int data_size, char bits, char endian)
{
	t_sh_info info;
	char	*ptr;

	if (bits == FT_B64)
	{
		ptr = get_data(data, 0x0, 0x40, data_size);
		if (!ptr)
		{
			info.error_code = -1;
			return (info);
		}
		info.offset = read_uint64(ptr + 0x28, endian);
		info.current_offset = read_uint64(ptr + 0x28, endian);
		info.entry_size = read_uint16(ptr + 0x3A, endian);
		info.number = read_uint16(ptr + 0x3C, endian);
		info.section_name_index = read_uint16(ptr + 0x3E, endian);
		info.error_code = 0;
	}
	else
	{
		ptr = get_data(data, 0x0, 0x434, data_size);
		if (!ptr)
		{
			info.error_code = -1;
			return (info);
		}
		info.offset = read_uint64(ptr + 0x20, endian);
		info.current_offset = read_uint64(ptr + 0x20, endian);
		info.entry_size = read_uint16(ptr + 0x2E, endian);
		info.number = read_uint16(ptr + 0x30, endian);
		info.section_name_index = read_uint16(ptr + 0x32, endian);
		info.error_code = 0;
	}
	return (info);
}

static
char	*get_strtab_elem
	(
		char *data,
		t_sh_info sh_info,
		uint16_t offset,
		int data_size,
		char bits,
		char endian,
		t_is_symbol is_symbol
	)
{
	char		*ptr;
	uintptr_t	str_offset;
	uintptr_t	len;

	if (is_symbol)
			ptr = get_data(
			data,
			sh_info.offset + sh_info.entry_size * sh_info.symbol_name_index,
			sh_info.entry_size,
			data_size
		);
	else
		ptr = get_data(
			data,
			sh_info.offset + sh_info.entry_size * sh_info.section_name_index,
			sh_info.entry_size,
			data_size
		);
	if (!ptr)
		return (NULL);
	if (bits == FT_B64)
	{
		str_offset = read_uint64(ptr + 0x18, endian);
		len = read_uint64(ptr + 0x20, endian);
	}
	else
	{
		str_offset = read_uint32(ptr + 0x10, endian);
		len = read_uint32(ptr + 0x14, endian);
	}
	ptr = get_data(data, str_offset, len, data_size);;
	if (!ptr)
		return (NULL);
	return (ptr + offset);
}

static
char	select_uplow(char sym, uint8_t bind)
{
	if (bind == STB_GLOBAL)
		return ((char) ft_toupper(sym));
	if (bind == STB_LOCAL)
		return ((char) ft_tolower(sym));
	return '!';
}

static
char	generate_symbol(uint8_t info, uint16_t ndx, uint8_t visibility, char *section_name, uint64_t section_flag, uint32_t section_type)
{
	uint8_t	type;
	uint8_t	bind;

	type = info & 0xf;
	bind = info >> 4;
	if (bind == STB_WEAK && type == STT_OBJECT &&
		(ndx == SHN_UNDEF || ndx == SHN_COMMON))
		return 'V';
	if (bind == STB_WEAK && type == STT_OBJECT)
		return 'v';
	if (bind == STB_WEAK && (ndx == SHN_UNDEF || ndx == SHN_COMMON))
		return 'w';
	if (bind == STB_WEAK)
		return 'W';
	if (ndx == SHN_UNDEF)
		return 'U';
	if (ndx == SHN_ABS)
		return select_uplow('A', bind);
	if (!ft_strcmp(".bss", section_name))
		return select_uplow('B', bind);
	if (type == STT_COMMON)
		return select_uplow('C', bind);
	if (!ft_strcmp(".text", section_name) || !ft_strcmp(".init", section_name) || !ft_strcmp(".fini", section_name))
		return select_uplow('T', bind);
	if (!(section_flag & 0x1))
		return select_uplow('R', bind);
	if (!ft_strcmp(".sbss", section_name))
		return select_uplow('G', bind);
	if ((section_type & SHT_PROGBITS) || (section_type & SHT_DYNAMIC))
		return select_uplow('D', bind);
	return '?';
	(void) visibility;
}

static
t_symbol_array	init_symbol_array(void)
{
	t_symbol_array	ret;

	ret.allocated = 8;
	ret.size = 0;
	ret.array = ft_calloc(8, sizeof (t_symbol));
	return (ret);
}

static
void	add_symbol(char *name, char symbol, uint64_t value, t_symbol_array array)
{
	t_symbol	*tmp;

	if (array.size == array.allocated)
	{
		tmp =  ft_calloc(array.allocated * 2, sizeof (t_symbol));
		ft_memmove(tmp, array.array, sizeof(t_symbol) * array.size);
		free(array.array);
		array.array = tmp;
		array.allocated *= 2;
	}
	array.array[array.size].name = name;
	array.array[array.size].symbol = symbol;
	array.array[array.size++].value = value;
}

static
void	print_symbols(t_symbol_array array,uint8_t flags, int has_to_print_name)
{
	//todo:
}

int	parse_file(char *path, uint8_t flags, int has_to_print_name)
// TODO: refacto that shit
{
	char			*data;
	int				data_size;
	char			endian;
	char			bits;
	t_sh_info		section_table_info;
	t_symbol_array	symbol_array;

	data_size = load_file(path, &data);
	symbol_array = init_symbol_array();
	if (data_size < 0)
		return (1);
	if (ft_memcmp(data, "\x7f""ELF", 4))
	{
		ft_printf("nm: %s: File format not recognized\n", path);
		return (1);
	}
	bits = get_data(data, 0x04, 1, data_size)[0];
	endian = get_data(data, 0x05, 1, data_size)[0];
	section_table_info = get_section_header_infos(data, data_size, bits, endian);
	if (section_table_info.error_code < 0)
	{
		// TODO: check this type of error with true nm
		ft_printf("nm: %s: Improper file format\n", path);
		return (1);
	}
	while (--(section_table_info.number))
	{
		char *ptr = get_data(data, section_table_info.current_offset, section_table_info.entry_size, data_size);
		if (!ptr)
		{
			// TODO: check this type of error with true nm
			ft_printf("nm: %s: Improper file format\n", path);
			return (1);
		}
		if (read_uint32(ptr + 0x04, endian) == SHT_SYMTAB)
		{
			uint64_t	symtab_offset;
			uint64_t	symtab_size;
			uint64_t	symtab_entrysize;
			uint64_t	nb_entry;
			uint32_t	link;

			if (bits == FT_B64)
			{
				symtab_offset = read_uint64(ptr + 0x18, endian);
				symtab_size = read_uint64(ptr + 0x20, endian);
				symtab_entrysize = read_uint64(ptr + 0x38, endian);
				link = read_uint32(ptr + 0x28, endian);
			}
			else
			{
				symtab_offset = read_uint32(ptr + 0x10, endian);
				symtab_size = read_uint32(ptr + 0x14, endian);
				symtab_entrysize = read_uint32(ptr + 0x24, endian);
				link = read_uint32(ptr + 0x18, endian);
			}
			section_table_info.symbol_name_index = link;
			char *ptr_symbol = get_data(data, symtab_offset, symtab_size, data_size);
			if (!ptr_symbol)
			{
				// TODO: check this type of error with true nm
				ft_printf("nm: %s: Improper file format\n", path);
				return (1);
			}
			nb_entry = symtab_size / symtab_entrysize;
			while (--nb_entry)
			{
				ptr_symbol += symtab_entrysize;
				uint64_t	value = read_uint64(ptr_symbol + 0x08, endian);
				char		*name = get_strtab_elem(data, section_table_info, read_uint32(ptr_symbol, endian), data_size, bits, endian, IS_SYMBOL);
				uint8_t		symbol_info = *(ptr_symbol + 0x04);
				uint8_t		visibility = *(ptr_symbol + 0x5);
				uint16_t	shndx = read_uint16(ptr_symbol + 0x06, endian);
				char		*offset_ptr = get_data(data, section_table_info.offset + shndx * section_table_info.entry_size, section_table_info.entry_size, data_size);
				char		*section_name = "";
				uint64_t	section_flag = 0;
				uint32_t	section_type = 0;
				if (offset_ptr)
				{
					section_name = get_strtab_elem(data, section_table_info, read_uint32(offset_ptr, endian), data_size, bits, endian, IS_SECTION);
					section_flag = read_uint64(offset_ptr + 0x08, endian);
					section_type = read_uint32(offset_ptr + 0x04, endian);
				}
				char		symbol = generate_symbol(symbol_info, shndx, visibility, section_name, section_flag, section_type);


				// TODO: change direct print for a storage: need to sort and filter that shit
				if (symbol == 'U' || symbol == 'V' || symbol == 'u' || symbol == 'v' || symbol == 'w')
					ft_printf("%16s %c %s\n", "", symbol, name);
				else
					ft_printf("%016lx %c %s\n", value, symbol, name);
				add_symbol(name, symbol, value, symbol_array);
			}
		}
		section_table_info.current_offset += section_table_info.entry_size;
	}
	print_symbols(symbol_array, flags, has_to_print_name);
	munmap(data, data_size);
	free(symbol_array.array);
	return (0);
}
