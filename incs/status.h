/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:13:47 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/01/18 14:49:05 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUS_H
# define STATUS_H

typedef enum {
	OK,
	NOT_IMPLEMENTED
}	t_codes;

enum e_implementation_status
{
	A_IS_IMPLEMENTED = NOT_IMPLEMENTED,
	G_IS_IMPLEMENTED = NOT_IMPLEMENTED,
	U_IS_IMPLEMENTED = NOT_IMPLEMENTED,
	R_IS_IMPLEMENTED = NOT_IMPLEMENTED,
	P_IS_IMPLEMENTED = NOT_IMPLEMENTED,
	V_IS_IMPLEMENTED = NOT_IMPLEMENTED,
	H_IS_IMPLEMENTED = NOT_IMPLEMENTED
};

#define REPORT_ADDRESS "https://github.com/laird-ikar/ft_nm/issues"

#endif
