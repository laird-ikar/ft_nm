/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:39:42 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/06/25 10:38:06 by yyyyyyyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "ft_memory.h"
# include "ft_string.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

# ifndef T_GNL
#  define T_GNL

typedef struct s_gnl
{
	int		ret;
	char	*tmp;
	char	*res;
	char	buff[BUFFER_SIZE + 2];
	int		i;
}			t_gnl;

# endif

/* Return the next line of the file described by fd
** NULL is nothing can be read*/
char	*get_next_line(int fd);

#endif
