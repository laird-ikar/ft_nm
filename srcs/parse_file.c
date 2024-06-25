/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:55:21 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/01/23 16:10:07 by ***REMOVED***           ###   ########.fr       */
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
		info.entry_size = read_uint16(ptr + 0x2E, endian);
		info.number = read_uint16(ptr + 0x30, endian);
		info.section_name_index = read_uint16(ptr + 0x32, endian);
		info.error_code = 0;
	}
	return (info);
}

int	parse_file(char *path, uint8_t flags, int has_to_print_name)
{
	char	*data;
	int		data_size;
	char	endian;
	char	bits;

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
	t_sh_info sh_infos
		= get_section_header_infos(data, data_size, bits, endian);
	if (sh_infos.error_code < 0)
	{
		// TODO: check this type of error with true nm
		ft_printf("nm: %s: Improper file format\n", path);
		return (1);
	}
	ft_printf("%p + %u * %u bits\n",
		(void *) sh_infos.offset, sh_infos.number, sh_infos.entry_size);
	munmap(data, data_size);
	return (0);
	(void) flags;
	(void) has_to_print_name;
}
