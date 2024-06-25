/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:55:21 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/01/24 18:02:05 by ***REMOVED***           ###   ########.fr       */
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

int	parse_file(char *path, uint8_t flags, int has_to_print_name)
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
				sh_infos.section_name_index = link;
				ft_printf("st_name: %u\n", read_uint32(ptr, endian));
				if (read_uint32(ptr, endian))
					ft_printf("name: %s\n", get_strtab_elem(data, sh_infos, read_uint32(ptr, endian), data_size, bits, endian));
				else
					ft_printf("name: NO_NAME\n");

				ptr += symtab_entrysize;
			}
		}
		sh_infos.current_offset += sh_infos.entry_size;
	}
	munmap(data, data_size);
	return (0);
	(void) flags;
	(void) has_to_print_name;
}
