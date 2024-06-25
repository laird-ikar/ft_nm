/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:59:17 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/01/31 17:53:23 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FILE_H
# define PARSE_FILE_H

#include <get_data.h>
#include <read_int.h>

#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <libft.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

typedef enum	e_is_symbol
{
	IS_SECTION,
	IS_SYMBOL
}	t_is_symbol;

// INFO: https://docs.oracle.com/cd/E19683-01/816-1386/chapter6-79797/index.html
enum	e_endians
{
	FT_SMALL_ENDIAN = 1,
	FT_BIG_ENDIAN = 2,
};

typedef struct	s_symbol
{
	char		*name;
	uint64_t	value;
	char		symbol;
}	t_symbol;

typedef struct	s_symbol_array
{
	t_symbol	*array;
	int			size;
	int			allocated;
}	t_symbol_array;

enum	e_bits
{
	FT_B32 = 1,
	FT_B64 = 2,
};

enum	e_symbol_types
{
	STT_NOTYPE = 0,
	STT_OBJECT = 1,
	STT_FUNC = 2,
	STT_SECTION = 3,
	STT_FILE = 4,
	STT_COMMON = 5,
	STT_LOOS = 10,
	STT_HIOS = 12,
	STT_LOPROC = 13,
	STT_SPARC_REGISTER = 13,
	STT_HIPROC = 15
};

enum	e_symbol_binds
{
	STB_LOCAL = 0,
	STB_GLOBAL = 1,
	STB_WEAK = 2,
	STB_LOOS = 10,
	STB_HIOS = 12,
	STB_LOPROC = 13,
	STB_HIPROC = 15
};

enum	e_shndx
{
	SHN_UNDEF = 0,
	SHN_LORESERVE = 0xff00,
	SHN_LOPROC = 0xff00,
	SHN_HIPROC = 0xff1f,
	SHN_LOOS = 0xff20,
	SHN_HIOS = 0xff3f,
	SHN_ABS = 	0xfff1,
	SHN_COMMON = 0xfff2,
	SHN_XINDEX = 0xffff,
	SHN_HIRESERVE = 0xffff,
};

enum	e_section_type
{
	SHT_PROGBITS = 0x1,
	SHT_SYMTAB = 0x2,
	SHT_DYNAMIC = 0x6
};

typedef struct s_sh_info
{
	int			error_code;
	uintptr_t	offset;
	uintptr_t	current_offset;
	uint16_t	entry_size;
	uint16_t	number;
	uint16_t	section_name_index;
	uint16_t	symbol_name_index;
}	t_sh_info;

int	parse_file(char *path, uint8_t flags, int has_to_print_name);

#endif
