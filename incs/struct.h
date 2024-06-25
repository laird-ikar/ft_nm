/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stage <***REMOVED***@***REMOVED***>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:57:40 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/06/05 11:31:23 by stage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <enum.h>

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
	int				size;
	t_error_code	status;
}	t_file;

typedef struct s_nm {
	t_file	file;
	t_input	input;
}	t_nm;

#endif
