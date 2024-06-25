/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:35:19 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/06/25 10:38:42 by yyyyyyyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <analyze_file.h>

/*
open(2) close(2) mmap(2) munmap(2) write(2)
fstat(2) malloc(3) free(3) exit(3) perror(3)
strerror(1)
*/

static
t_file	load_file_error(char *message, char *path, int error)
{
	t_file	error_file;

	ft_bzero(&error_file, sizeof (t_file));
	error_file.status = error;
	ft_putstr_fd(message, STDIN_FILENO);
	perror(path);
	return (error_file);
}

static
t_file	load_file(char *path)
{
	int			fd;
	struct stat	file_stats;
	t_file		file;

	ft_bzero(&file, sizeof (t_file));
	file.status = SUCCESS;
	fd = open(path, O_RDONLY);
	if (fd < 1)
		return load_file_error("ft_nm: open: ", path, OPEN_ERROR);
	if (fstat(fd, &file_stats) < 0)
		return load_file_error("ft_nm: fstat: ", path, FSTAT_ERROR);
	file.size = file_stats.st_size;
	if (file.size == 0)
	{
		file.status = EMPTY_FILE;
		return file;
	}
	file.raw_data = mmap(0, file.size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (file.raw_data == MAP_FAILED)
		return(load_file_error("ft_nm: mmap: ", path, MMAP_ERROR));
	close(fd);
	return (file);
}

void	load_elf_header(t_nm *nm)
{
	if (nm->file.size < sizeof (t_indent))
	{
		nm->file.status = MALFORMED_FILE;
		return ;
	}
	ft_memcpy(&nm->elf.header.indent, nm->file.raw_data, sizeof (t_indent));
	if (nm->elf.header.indent.magic != 0x464c457f)
	{
		nm->file.status = MALFORMED_FILE;
		return ;
	}
	if (nm->elf.header.indent.class == EI_CLASS_32BIT && nm->file.size >= sizeof (t_indent) + sizeof (t_32bits_header))
		ft_memmove(&nm->elf.header._32bits, nm->file.raw_data + sizeof (t_indent), sizeof (t_32bits_header));
	else if (nm->elf.header.indent.class == EI_CLASS_64BIT && nm->file.size >= sizeof (t_indent) + sizeof (t_64bits_header))
		ft_memmove(&nm->elf.header._64bits, nm->file.raw_data + sizeof (t_indent), sizeof (t_64bits_header));
	else
		nm->file.status = MALFORMED_FILE;
}

int	analyze_file(char *file_path, t_nm nm)
{
	nm.file = load_file(file_path);
	if (nm.file.status != SUCCESS)
		return 1;
	load_elf_header(&nm);
	if (nm.file.status != SUCCESS)
	{
		ft_putstr_fd("ft_nm: ", STDIN_FILENO);
		ft_putstr_fd(file_path, STDIN_FILENO);
		ft_putstr_fd(": file format not recognized\n", STDIN_FILENO);
		munmap(nm.file.raw_data, nm.file.size);
		return 1;
	}
	if (nm.elf.header.indent.class == EI_CLASS_32BIT)
		return analyze_file_32bits(&nm, file_path);
	else if (nm.elf.header.indent.class == EI_CLASS_64BIT)
		return analyze_file_64bits(&nm, file_path);
	else {
		ft_putstr_fd("ft_nm: ", STDIN_FILENO);
		ft_putstr_fd(file_path, STDIN_FILENO);
		ft_putstr_fd(": file format not recognized\n", STDIN_FILENO);
		munmap(nm.file.raw_data, nm.file.size);
		return 1;
	}
}
