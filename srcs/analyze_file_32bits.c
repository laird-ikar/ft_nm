/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_file_32bits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:16:57 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/06/21 15:11:21 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <analyze_file_32bits.h>

static
char	*load_name(t_nm *nm, uint32_t name_offset, uint32_t name_table_offset)
{
	return ((char *) nm->file.raw_data + name_table_offset + name_offset);
}

static
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
			ft_isalnum(a.name[a_i])
			&& ft_isalnum(b.name[b_i])
			&& ft_toupper(a.name[a_i]) != ft_toupper(b.name[b_i])
		)
			return (ft_toupper(a.name[a_i]) - ft_toupper(b.name[b_i]));
		a_i++;
		b_i++;
	}
	if (a.name[a_i] && !b.name[b_i])
		return (1);
	if (!a.name[a_i] && b.name[b_i])
		return (-1);
	if (ft_strcmp(a.name, b.name))
		return (ft_strcmp(a.name, b.name));
	return (a._32bits.value - b._32bits.value);
}

static
int rev_compare(t_symbol a, t_symbol b)
{
	return (-compare(a, b));
}

static
void	load_sections(t_nm *nm)
{
	int	i;

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
static
void	load_symbols(t_nm *nm)
{
	unsigned int	i;
	unsigned int	ii;
	unsigned int	nb_sections;

	nb_sections = nm->elf.header._32bits.shnum;
	i = 0;
	while (i < nb_sections)
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

				ii++;
			}
		}
		i++;
	}
}

static
void	print_symbols(t_nm *nm)
{
	t_symbol		*symbols;
	unsigned int	total_symbols;
	unsigned int	i;

	total_symbols = 0;
	i = 0;
	while (i < nm->elf.header._32bits.shnum)
	{
		if (nm->elf.sections[i].symbols)
		{
			total_symbols += nm->elf.sections[i]._32bits.size / nm->elf.sections[i]._32bits.entsize;
		}
		i++;
	}
	symbols = ft_calloc(total_symbols, sizeof (t_symbol));
	i = 0;
	total_symbols = 0;
	while (i < nm->elf.header._32bits.shnum)
	{
		if (nm->elf.sections[i].symbols)
		{
			ft_memcpy(
				symbols + total_symbols,
				nm->elf.sections[i].symbols,
				sizeof (t_symbol) * (nm->elf.sections[i]._32bits.size / nm->elf.sections[i]._32bits.entsize)
			);
			total_symbols += nm->elf.sections[i]._32bits.size / nm->elf.sections[i]._32bits.entsize;
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
			// char		*section_name;

			symbol_type = symbols[i]._32bits.info & 0xf;
			symbol_bind = symbols[i]._32bits.info >> 4;
			symbol_visibility = symbols[i]._32bits.other & 0x3;
			shndx = symbols[i]._32bits.shndx;
			if (symbol_type == STT_NOTYPE)
				c = '?';
			else if (symbol_type == STT_OBJECT)
				c = 'D';
			else if (symbol_type == STT_FUNC)
				c = 'T';
			else if (symbol_type == STT_SECTION)
				c = 'N';
			else if (symbol_type == STT_FILE)
				c = 'N';
			else if (symbol_type == STT_COMMON)
				c = 'C';
			else if (symbol_type == STT_TLS)
				c = 'D';
			else
				c = '?';
			if (shndx == SHN_ABS)
				c = 'A';
			else if (shndx == SHN_COMMON)
				c = 'C';
			else if (symbol_bind == STB_WEAK)
			{
				if (symbol_type == STT_OBJECT)
				{
					if (shndx != SHN_UNDEF)
						c = 'V';
					else
						c = 'v';
				}
				else
				{
					if (shndx != SHN_UNDEF)
						c = 'W';
					else
						c = 'w';
				}
			}
			else if (shndx == SHN_UNDEF)
				c = 'U';
			else {
				uint32_t section_type = nm->elf.sections[shndx]._32bits.type;
				if (section_type == SHT_NOBITS)
					c = 'B';
				else if (section_type == SHT_PROGBITS || section_type == SHT_NOTE)
				{
					uint32_t section_flags = nm->elf.sections[shndx]._32bits.flags;
					if (section_flags & SHF_EXECINSTR) {
						c = 'T';  // Text (code) section
					} else if (section_flags & SHF_ALLOC) {
						if (section_flags & SHF_WRITE) {
							c = 'D';
						} else {
							c = 'R';
						}
					}
				}
			}
			if (symbol_bind == STB_LOCAL && c != 'W' && c != 'V')
				c = ft_tolower(c);
			if (i == 1)
				c = 'a';
			if ((symbols[i]._32bits.value != 0 || c == 'u' || c == 'a' || c == 'b') && c != 'U')
				ft_printf("%08x %c %s\n", symbols[i]._32bits.value, c, symbols[i].name);
			else
				ft_printf("%8c %c %s\n", ' ', c, symbols[i].name);
		}
		i++;
	}
	free(symbols);
}

static
void cleanup(t_nm *nm)
{
	unsigned int	i;
	unsigned int	nb_sections;

	nb_sections = nm->elf.header._32bits.shnum;
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

void	analyze_file_32bits(t_nm *nm)
{
	load_sections(nm);
	load_symbols(nm);
	print_symbols(nm);
	cleanup(nm);
}
