/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:55:21 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/01/30 11:55:01 by ***REMOVED***           ###   ########.fr       */
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
		char endian
	)
{
	char		*ptr;
	uintptr_t	str_offset;
	uintptr_t	len;

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
char	generate_symbol(uint8_t info, uint16_t shndx, uint8_t visibility)
{
	uint8_t	symbol_type;
	uint8_t	symbol_bind;

	symbol_type  = info & 0xf;
	symbol_bind  = info >> 4;

	ft_printf("type:%x bind:%x ndx:%x :::::: ", symbol_type, symbol_bind, shndx);

	if (shndx == SHN_ABS)
		return select_uplow('A', symbol_bind);
	if (symbol_type == STT_OBJECT && (shndx == SHN_UNDEF))
		return select_uplow('B', symbol_bind);
	if (symbol_type == STT_OBJECT && shndx == SHN_COMMON)
		return select_uplow('C', symbol_bind);
	if (symbol_type == STT_OBJECT && shndx != SHN_UNDEF &&
			shndx != SHN_COMMON)
		return select_uplow('D', symbol_bind);
	if (symbol_type == STT_FUNC && shndx != SHN_UNDEF &&
			shndx != SHN_COMMON)
		return 'T';
	if (symbol_bind == STB_WEAK && symbol_type == STT_OBJECT &&
		(shndx == SHN_UNDEF || shndx == SHN_COMMON))
		return 'V';
	if (symbol_bind == STB_WEAK && symbol_type == STT_OBJECT)
		return 'v';
	if (symbol_bind == STB_WEAK && (shndx == SHN_UNDEF || shndx == SHN_COMMON))
		return 'w';
	if (symbol_bind == STB_WEAK)
		return 'W';
	if (shndx == SHN_UNDEF)
		return 'U';
	return '?';
	(void) visibility;
}

int	parse_file(char *path, uint8_t flags, int has_to_print_name)
// TODO: refacto that shit
{
	char		*data;
	int			data_size;
	char		endian;
	char		bits;
	t_sh_info	sh_infos;

	data_size = load_file(path, &data);
	if (data_size < 0)
		return (1);
	if (ft_memcmp(data, "\x7f""ELF", 4))
	{
		ft_printf("nm: %s: File format not recognized\n", path);
		return (1);
	}
	bits = get_data(data, 0x04, 1, data_size)[0];
	endian = get_data(data, 0x05, 1, data_size)[0];
	sh_infos = get_section_header_infos(data, data_size, bits, endian);
	if (sh_infos.error_code < 0)
	{
		// TODO: check this type of error with true nm
		ft_printf("nm: %s: Improper file format\n", path);
		return (1);
	}
	while (--(sh_infos.number))
	{
		char *ptr = get_data(data, sh_infos.current_offset, sh_infos.entry_size, data_size);
		if (!ptr)
		{
			// TODO: check this type of error with true nm
			ft_printf("nm: %s: Improper file format\n", path);
			return (1);
		}
		if (read_uint32(ptr + 0x04, endian) == SYMTAB_TAG)
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
			ft_printf("offset: %p, size: %p, entry_size: %p\n", (void *) symtab_offset, (void *) symtab_size, (void *) symtab_entrysize);
			ptr = get_data(data, symtab_offset, symtab_size, data_size);
			if (!ptr)
			{
				// TODO: check this type of error with true nm
				ft_printf("nm: %s: Improper file format\n", path);
				return (1);
			}
			nb_entry = symtab_size / symtab_entrysize;
			while (--nb_entry)
			{
				ptr += symtab_entrysize;
				uint64_t	value = read_uint64(ptr + 0x08, endian);
				char		*name = get_strtab_elem(data, sh_infos, read_uint32(ptr, endian), data_size, bits, endian);
				uint8_t		info = *(ptr + 0x04);
				uint8_t		visibility = *(ptr + 0x5);
				uint16_t	shndx = read_uint16(ptr + 0x06, endian);
				char		symbol = generate_symbol(info, shndx, visibility);


				// TODO: change direct print for a storage: need to sort and filter that shit
				sh_infos.section_name_index = link;
				ft_printf("%016lx %c %s\n", value, symbol, name);
			}
		}
		sh_infos.current_offset += sh_infos.entry_size;
	}
	munmap(data, data_size);
	return (0);
	(void) flags;
	(void) has_to_print_name;
}
