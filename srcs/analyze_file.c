/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:35:19 by stage             #+#    #+#             */
/*   Updated: 2024/06/13 18:00:32 by ***REMOVED***           ###   ########.fr       */
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

void	load_sections(t_nm *nm)
{
	int	i;

	if (nm->elf.header.indent.class == EI_CLASS_32BIT)
	{
		if (nm->elf.header._32bits.shoff + nm->elf.header._32bits.shnum * nm->elf.header._32bits.shentsize > nm->file.size)
		{
			nm->file.status = MALFORMED_FILE;
			return ;
		}
		nm->elf.sections = ft_calloc(nm->elf.header._32bits.shnum, sizeof (t_section));
		i = 0;
		while (i < nm->elf.header._32bits.shnum)
		{
			ft_memcpy(nm->elf.sections + i, nm->file.raw_data + nm->elf.header._32bits.shoff + i * nm->elf.header._32bits.shentsize, nm->elf.header._32bits.shentsize);
			i++;
		}
	}
	else if (nm->elf.header.indent.class == EI_CLASS_64BIT)
	{
		if (nm->elf.header._64bits.shoff + nm->elf.header._64bits.shnum * nm->elf.header._64bits.shentsize > nm->file.size)
		{
			nm->file.status = MALFORMED_FILE;
			return ;
		}
		nm->elf.sections = ft_calloc(nm->elf.header._64bits.shnum, sizeof (t_section));
		i = 0;
		while (i < nm->elf.header._64bits.shnum)
		{
			ft_memcpy(nm->elf.sections + i, nm->file.raw_data + nm->elf.header._64bits.shoff + i * nm->elf.header._64bits.shentsize, nm->elf.header._64bits.shentsize);
			i++;
		}
	}
	else
		nm->file.status = MALFORMED_FILE;
}

void	load_symbols(t_nm *nm)
{
	(void) nm;
}

void	print_symbols(t_nm *nm)
{
	(void) nm;
}

char	*load_name(t_nm *nm, uint32_t name_offset, uint32_t name_table_offset)
{
	if (nm->file.size < name_table_offset + name_offset)
		return (NULL);
	return ((char *) nm->file.raw_data + name_table_offset + name_offset);
}
#ifdef FT_DEBUG_MODE
void	print_sections(t_nm *nm)
{
	uint16_t	nb_sections;
	char		*name;

	ft_printf("\033[1;33m");
	if (nm->elf.header.indent.class == EI_CLASS_32BIT)
		nb_sections = nm->elf.header._32bits.shnum;
	else
		nb_sections = nm->elf.header._64bits.shnum;
	ft_printf("%d SECTION(S):\n", nb_sections);
	for (int i = 0; i < nb_sections; i++)
	{
		if (nm->elf.header.indent.class == EI_CLASS_32BIT)
			name = load_name(nm, nm->elf.sections[i]._32bits.name, nm->elf.sections[nm->elf.header._32bits.shstrndx]._32bits.offset);
		else
			name = load_name(nm, nm->elf.sections[i]._64bits.name, nm->elf.sections[nm->elf.header._64bits.shstrndx]._64bits.offset);
		ft_printf("%3d: %s\n", i, name);
	}
	ft_printf("\033[0m");
}
#endif

void	analyze_file(char *file_path, t_nm nm)
{
	nm.file = load_file(file_path);
	if (nm.file.status != SUCCESS)
		return ;
	#ifndef FT_DEBUG_MODE
	if (nm.input.files.nb_elem > 1)
	#endif
		ft_printf("\n%s:\n", file_path);
	load_elf_header(&nm);
	if (nm.file.status != SUCCESS)
	{
		ft_putstr_fd("ft_nm: ", STDIN_FILENO);
		ft_putstr_fd(file_path, STDIN_FILENO);
		ft_putstr_fd(": File format not recognized\n", STDIN_FILENO);
		munmap(nm.file.raw_data, nm.file.size);
		return ;
	}
	load_sections(&nm);
	#ifdef FT_DEBUG_MODE
	print_sections(&nm);
	#endif
	load_symbols(&nm);
	print_symbols(&nm);
	free(nm.elf.sections);
	munmap(nm.file.raw_data, nm.file.size);
}
