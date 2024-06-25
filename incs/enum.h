/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:46:25 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/06/21 15:41:18 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

enum	e_flag_mode {
	ACTIVE = 1
};

typedef enum e_error_codes {
	SUCCESS,
	INVALID_FLAG,
	FAILED_ALLOCATION,
	FSTAT_ERROR,
	OPEN_ERROR,
	MMAP_ERROR,
	MALFORMED_FILE,
	EMPTY_FILE,
	MALLOC_ERROR
}	t_error_code;

enum e_ei_class {
	EI_CLASS_32BIT = 1,
	EI_CLASS_64BIT = 2,
};

enum e_sh_type {
	SHT_NULL = 0,
	SHT_PROGBITS = 1,
	SHT_SYMTAB = 0x2,
	SHT_NOTE = 0x07,
	SHT_NOBITS = 0x8,
	SHT_DYNSYM = 0xB,
};

enum e_stv {
	STV_DEFAULT = 0,
	STV_INTERNAL = 1,
	STV_HIDDEN = 2,
	STV_PROTECTED = 3,
};

enum e_stb {
	STB_LOCAL = 0,
	STB_GLOBAL = 1,
	STB_WEAK = 2,
	STB_NUM = 3,
	STB_LOOS = 10,
	STB_HIOS = 12,
	STB_LOPROC = 13,
	STB_HIPROC = 15,
};

enum e_shf {
	SHF_WRITE = 0x1,
	SHF_ALLOC = 0x2,
	SHF_EXECINSTR = 0x4,
	SHF_MERGE = 0x10,
	SHF_STRINGS = 0x20,
	SHF_INFO_LINK = 0x40,
	SHF_LINK_ORDER = 0x80,
	SHF_OS_NONCONFORMING = 0x100,
	SHF_GROUP = 0x200,
	SHF_TLS = 0x400,
	SHF_MASKOS = 0x0FF00000,
	SHF_MASKPROC = 0xF0000000,
};

enum e_stt {
	STT_NOTYPE = 0,
	STT_OBJECT = 1,
	STT_FUNC = 2,
	STT_SECTION = 3,
	STT_FILE = 4,
	STT_COMMON = 5,
	STT_TLS = 6,
	STT_NUM = 7,
	STT_LOOS = 10,
	STT_HIOS = 12,
	STT_LOPROC = 13,
	STT_HIPROC = 15,
};

enum e_shn {
	SHN_UNDEF = 0,
	SHN_LORESERVE = 0xFF00,
	SHN_LOPROC = 0xFF00,
	SHN_HIPROC = 0xFF1F,
	SHN_ABS = 0xFFF1,
	SHN_COMMON = 0xFFF2,
	SHN_HIRESERVE = 0xFFFF,
};

#endif
