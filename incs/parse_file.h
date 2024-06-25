/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:59:17 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/01/25 16:40:23 by ***REMOVED***           ###   ########.fr       */
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

// INFO: https://docs.oracle.com/cd/E19683-01/816-1386/chapter6-79797/index.html
enum	e_endians
{
	FT_SMALL_ENDIAN = 1,
	FT_BIG_ENDIAN = 2,
};

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

};

enum	e_symbol_binds
{};

enum	e_shndx
{};

#define	SYMTAB_TAG	0x2

typedef struct s_sh_info
{
	int			error_code;
	uintptr_t	offset;
	uintptr_t	current_offset;
	uint16_t	entry_size;
	uint16_t	number;
	uint16_t	section_name_index;
}	t_sh_info;

int	parse_file(char *path, uint8_t flags, int has_to_print_name);

#endif
