/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:46:25 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/06/12 16:28:11 by ***REMOVED***           ###   ########.fr       */
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
}	t_error_code;

enum e_ei_class {
	EI_CLASS_32BIT = 1,
	EI_CLASS_64BIT = 2,
};

#endif
