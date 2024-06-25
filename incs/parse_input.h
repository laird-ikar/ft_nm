/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:20:30 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/05/02 13:48:39 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INPUT_H
# define PARSE_INPUT_H

# include <struct.h>
# include <libft.h>
# include <enum.h>
# include <ft_error.h>
# include <print_help.h>

/**
 *	@brief		Parse the user input and populate a `t_input`
 					with the flags and objfiles.
 *	@returns	A `t_input` filled with adequate data.
 *	@note		The `files` field is allocated and must be free'sd.
 */
t_input	parse_input(int argc, char *argv[], t_nm nm);

#endif
