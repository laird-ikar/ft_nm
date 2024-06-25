/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stage <***REMOVED***@***REMOVED***>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:35:19 by stage             #+#    #+#             */
/*   Updated: 2024/06/05 11:41:36 by stage            ###   ########.fr       */
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
	file.raw_data = mmap(0, file.size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (file.raw_data == MAP_FAILED)
		return(load_file_error("ft_nm: mmap: ", path, MMAP_ERROR));
	close(fd);
	return (file);
}

void	load_elf_header(t_nm *nm)
{
	(void) nm;
}

void	load_sections(t_nm *nm)
{
	(void) nm;
}

void	load_symbols(t_nm *nm)
{
	(void) nm;
}

void	print_symbols(t_nm *nm)
{
	(void) nm;
}

void	analyze_file(char *file_path, t_nm nm)
{
	nm.file = load_file(file_path);
	if (nm.file.status != SUCCESS)
		return ;
	if (nm.input.files.nb_elem > 1)
		ft_printf("\n%s:\n", file_path);
	load_elf_header(&nm);
	load_sections(&nm);
	load_symbols(&nm);
	print_symbols(&nm);
	munmap(nm.file.raw_data, nm.file.size);
}
