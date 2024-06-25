/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:57:40 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/06/12 17:06:02 by ***REMOVED***           ###   ########.fr       */
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

typedef struct s_elf {
	t_header	header;
}	t_elf;

typedef struct s_nm {
	t_file	file;
	t_input	input;
	t_elf	elf;
}	t_nm;

#endif
