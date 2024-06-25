/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:57:40 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/06/25 10:38:05 by yyyyyyyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <enum.h>
# include <stdint.h>
# include <stddef.h>

typedef struct s_array_2d
{
	char	**data;
	int		nb_elem;
	int		nb_allocated;
}	t_array_2d;

typedef struct s_input {
	int			debug_symbols;
	int			extern_only;
	int			undefined_only;
	int			reverse_sort;
	int			no_sort;
	int			help;
	t_array_2d	files;
}	t_input;

typedef struct s_file {
	char			*raw_data;
	size_t			size;
	t_error_code	status;
}	t_file;

typedef struct s_indent {
	uint32_t	magic;
	uint8_t		class;
	uint8_t		data;
	uint8_t		version;
	uint8_t		osabi;
	uint8_t		abiversion;
	uint8_t		padding[7];
}	t_indent;

typedef struct s_64bits_header {
	uint16_t	type;
	uint16_t	machine;
	uint32_t	version;
	uint64_t	entry;
	uint64_t	phoff;
	uint64_t	shoff;
	uint32_t	flags;
	uint16_t	ehsize;
	uint16_t	phentsize;
	uint16_t	phnum;
	uint16_t	shentsize;
	uint16_t	shnum;
	uint16_t	shstrndx;
}	t_64bits_header;

typedef struct s_32bits_header {
	uint16_t	type;
	uint16_t	machine;
	uint32_t	version;
	uint32_t	entry;
	uint32_t	phoff;
	uint32_t	shoff;
	uint32_t	flags;
	uint16_t	ehsize;
	uint16_t	phentsize;
	uint16_t	phnum;
	uint16_t	shentsize;
	uint16_t	shnum;
	uint16_t	shstrndx;
}	t_32bits_header;

typedef struct s_header {
	t_indent	indent;
	union {
		t_32bits_header	_32bits;
		t_64bits_header	_64bits;
	};
}	t_header;

typedef struct s_64bits_section {
	uint32_t	name;
	uint32_t	type;
	uint64_t	flags;
	uint64_t	addr;
	uint64_t	offset;
	uint64_t	size;
	uint32_t	link;
	uint32_t	info;
	uint64_t	addralign;
	uint64_t	entsize;
}	t_64bits_section;

typedef struct s_32bits_section {
	uint32_t	name;
	uint32_t	type;
	uint32_t	flags;
	uint32_t	addr;
	uint32_t	offset;
	uint32_t	size;
	uint32_t	link;
	uint32_t	info;
	uint32_t	addralign;
	uint32_t	entsize;
}	t_32bits_section;

typedef struct s_symbol_64bits {
	uint32_t	name;
	uint8_t		info;
	uint8_t		other;
	uint16_t	shndx;
	uint64_t	value;
	uint64_t	size;
} t_symbol_64bits;

typedef struct s_symbol_32bits {
	uint32_t	name;
	uint8_t		info;
	uint8_t		other;
	uint16_t	shndx;
	uint32_t	value;
	uint32_t	size;
} t_symbol_32bits;

typedef struct s_symbol {
	union {
		t_symbol_32bits	_32bits;
		t_symbol_64bits	_64bits;
	};
	char	*name;
	int		should_skip;
}	t_symbol;

typedef struct s_section {
	union {
		t_32bits_section	_32bits;
		t_64bits_section	_64bits;
	};
	t_symbol	*symbols;
}	t_section;

typedef struct s_elf {
	t_header	header;
	t_section	*sections;
}	t_elf;

typedef struct s_nm {
	t_file	file;
	t_input	input;
	t_elf	elf;
}	t_nm;

#endif
