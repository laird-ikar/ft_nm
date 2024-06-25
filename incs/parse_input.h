/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:20:30 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/06/25 10:38:05 by yyyyyyyy         ###   ########.fr       */
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
