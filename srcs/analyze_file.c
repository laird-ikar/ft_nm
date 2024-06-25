/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:35:19 by stage             #+#    #+#             */
/*   Updated: 2024/06/14 18:05:48 by ***REMOVED***           ###   ########.fr       */
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

char	*load_name(t_nm *nm, uint32_t name_offset, uint32_t name_table_offset)
{
	// if (nm->file.size < name_table_offset + name_offset)
	// 	return (NULL);
	return ((char *) nm->file.raw_data + name_table_offset + name_offset);
}

void	load_symbols(t_nm *nm)
{
	unsigned int	i;
	unsigned int	ii;
	unsigned int	nb_sections;

	if (nm->elf.header.indent.class == EI_CLASS_32BIT)
		nb_sections = nm->elf.header._32bits.shnum;
	else
		nb_sections = nm->elf.header._64bits.shnum;
	i = 0;
	while (i < nb_sections)
	{
		if (nm->elf.header.indent.class == EI_CLASS_32BIT)
		{
			if (nm->elf.sections[i]._32bits.type == SHT_SYMTAB)
			{
				if (nm->elf.sections[i]._32bits.offset + nm->elf.sections[i]._32bits.size > nm->file.size)
				{
					nm->file.status = MALFORMED_FILE;
					return ;
				}
				nm->elf.sections[i].symbols = ft_calloc(nm->elf.sections[i]._32bits.size / nm->elf.sections[i]._32bits.entsize, sizeof (t_symbol));
				ii = 0;
				while (ii < nm->elf.sections[i]._32bits.size / nm->elf.sections[i]._32bits.entsize)
				{
					ft_memcpy(
						&(nm->elf.sections[i].symbols[ii]._32bits),
						nm->file.raw_data + nm->elf.sections[i]._32bits.offset
							+ ii * nm->elf.sections[i]._32bits.entsize,
						nm->elf.sections[i]._32bits.entsize
					);
					nm->elf.sections[i].symbols[ii].name
						= load_name(
							nm, nm->elf.sections[i].symbols[ii]._32bits.name,
							nm->elf.sections[nm->elf.sections[i]._32bits.link]
								._32bits.offset
						);
					if (nm->elf.sections[i].symbols[ii].name == NULL)
					{
						ft_printf("name is null\n");
					}
					ii++;
				}
			}
		}
		else
		{
			if (nm->elf.sections[i]._64bits.type == SHT_SYMTAB)
			{
				if (nm->elf.sections[i]._64bits.offset + nm->elf.sections[i]._64bits.size > nm->file.size)
				{
					nm->file.status = MALFORMED_FILE;
					return ;
				}
				nm->elf.sections[i].symbols = ft_calloc(nm->elf.sections[i]._64bits.size / nm->elf.sections[i]._64bits.entsize, sizeof (t_symbol));
				ii = 0;
				while (ii < nm->elf.sections[i]._64bits.size / nm->elf.sections[i]._64bits.entsize)
				{
					ft_memcpy(
						&(nm->elf.sections[i].symbols[ii]._64bits),
						nm->file.raw_data + nm->elf.sections[i]._64bits.offset
							+ ii * nm->elf.sections[i]._64bits.entsize,
						nm->elf.sections[i]._64bits.entsize
					);
					// ft_printf("text %d\n", nm->elf.sections[i]._64bits.link);
					// ft_printf("idx %x\n", nm->elf.sections[i].symbols[ii]._64bits.name);
					nm->elf.sections[i].symbols[ii].name
						= load_name(
							nm, nm->elf.sections[i].symbols[ii]._64bits.name,
							nm->elf.sections[nm->elf.sections[i]._64bits.link]
								._64bits.offset
						);

					ii++;
				}
			}
		}
		i++;
	}
}

void	print_symbols_32bits(t_nm *nm)
{
	(void) nm;
}

int compare(t_symbol a, t_symbol b)
{
	int a_i;
	int b_i;

	if (a.name == NULL || b.name == NULL)
		return (0);
	a_i = 0;
	b_i = 0;
	while (a.name[a_i] && b.name[b_i])
	{
		while (a.name[a_i] && !ft_isalnum(a.name[a_i]))
			a_i++;
		while (b.name[b_i] && !ft_isalnum(b.name[b_i]))
			b_i++;
		if (
			(ft_toupper(a.name[a_i]) >= 'A' && ft_toupper(a.name[a_i]) <= 'Z')
			&& (ft_toupper(b.name[b_i]) >= 'A' && ft_toupper(b.name[b_i]) <= 'Z')
			&& ft_toupper(a.name[a_i]) != ft_toupper(b.name[b_i])
		)
			return (ft_toupper(a.name[a_i]) - ft_toupper(b.name[b_i]));
		a_i++;
		b_i++;
	}
	return (ft_strcmp(a.name, b.name));
}

int rev_compare(t_symbol a, t_symbol b)
{
	return (-compare(a, b));
}

void swap(t_symbol* a, t_symbol* b)
{
	t_symbol temp = *a;
	*a = *b;
	*b = temp;
}

// Partition function
int partition(t_symbol *symbols, int low, int high, int (*f_comp)(t_symbol, t_symbol))
{
	t_symbol	pivot = symbols[low];
	int			i = low;
	int			j = high;

	while (i < j) {
		while (f_comp(symbols[i], pivot) <= 0 && i <= high - 1) {
			i++;
		}
		while (f_comp(symbols[j], pivot) > 0 && j >= low + 1) {
			j--;
		}
		if (i < j) {
			swap(&symbols[i], &symbols[j]);
		}
	}
	swap(&symbols[low], &symbols[j]);
	return j;
}

void quick_sort(t_symbol *symbols, int low, int high, int (*f_comp)(t_symbol, t_symbol))
{
	if (low < high) {
		int partitionIndex = partition(symbols, low, high, f_comp);
		quick_sort(symbols, low, partitionIndex - 1, f_comp);
		quick_sort(symbols, partitionIndex + 1, high, f_comp);
	}
}

void	print_symbols_64bits(t_nm *nm)
{
	t_symbol		*symbols;
	unsigned int	total_symbols;
	unsigned int	i;

	total_symbols = 0;
	i = 0;
	while (i < nm->elf.header._64bits.shnum)
	{
		if (nm->elf.sections[i].symbols)
		{
			total_symbols += nm->elf.sections[i]._64bits.size / nm->elf.sections[i]._64bits.entsize;
		}
		i++;
	}
	symbols = ft_calloc(total_symbols, sizeof (t_symbol));
	i = 0;
	total_symbols = 0;
	while (i < nm->elf.header._64bits.shnum)
	{
		if (nm->elf.sections[i].symbols)
		{
			ft_memcpy(
				symbols + total_symbols,
				nm->elf.sections[i].symbols,
				sizeof (t_symbol) * (nm->elf.sections[i]._64bits.size / nm->elf.sections[i]._64bits.entsize)
			);
			total_symbols += nm->elf.sections[i]._64bits.size / nm->elf.sections[i]._64bits.entsize;
		}
		i++;
	}
	if (nm->input.no_sort)
		;
	else if (nm->input.reverse_sort)
		quick_sort(symbols, 0, total_symbols - 1, rev_compare);
	else
		quick_sort(symbols, 0, total_symbols - 1, compare);
	// TODO: filter symbols
	i = 1;
	while (i < total_symbols)
	{
		if (!symbols[i].should_skip)
		{
			char		symbol_type;
			char		symbol_bind;
			char		symbol_visibility;
			uint16_t	shndx;
			char		c;
			char		*section_name;

			symbol_type = symbols[i]._64bits.info & 0xf;
			symbol_bind = symbols[i]._64bits.info >> 4;
			symbol_visibility = symbols[i]._64bits.other & 0x3;
			shndx = symbols[i]._64bits.shndx;
			section_name = load_name(nm, nm->elf.sections[shndx]._64bits.name, nm->elf.sections[nm->elf.header._64bits.shstrndx]._64bits.offset);
			c = '?';
			if (shndx == SHN_ABS)
				c = 'A';
			else if (!ft_strcmp(".bbs", section_name))
			{
				if (symbol_visibility == STV_INTERNAL)
					c = 'b';
				else
					c = 'B';
			}
			ft_printf("ALL SYMBOLS VALUES: type: %d, bind: %d, visibility: %d\n, shndx: %d\n", symbol_type, symbol_bind, symbol_visibility, symbols[i]._64bits.shndx);
			ft_printf("%016lx %c %s\n", symbols[i]._64bits.value, c, symbols[i].name);
		}
		i++;
	}
	free(symbols);
}

void	print_symbols(t_nm *nm)
{
	if (nm->elf.header.indent.class == EI_CLASS_32BIT)
		print_symbols_32bits(nm);
	else
		print_symbols_64bits(nm);
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

void cleanup(t_nm *nm)
{
	unsigned int	i;
	unsigned int	nb_sections;

	if (nm->elf.header.indent.class == EI_CLASS_32BIT)
		nb_sections = nm->elf.header._32bits.shnum;
	else
		nb_sections = nm->elf.header._64bits.shnum;
	i = 0;
	while (i < nb_sections)
	{
		if (nm->elf.sections[i].symbols)
		{
			free(nm->elf.sections[i].symbols);
			nm->elf.sections[i].symbols = NULL;
		}
		i++;
	}
	free(nm->elf.sections);
	munmap(nm->file.raw_data, nm->file.size);
}

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
	cleanup(&nm);
}
