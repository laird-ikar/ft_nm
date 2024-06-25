/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:57:40 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/05/02 13:55:01 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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

typedef struct s_nm {
	t_input	input;
}	t_nm;

#endif
