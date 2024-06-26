/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:43:37 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/07/02 12:38:49 by yyyyyyyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "ft_buff.h"
# include "ft_list.h"
# include "ft_string.h"
# include "ft_cast.h"
# include "ft_math.h"

int		ft_printf(const char *str, ...)
		__attribute__ ((format (printf, 1, 2)));

int		ft_dprintf(int fd, const char *ft_format, ...)
		__attribute__ ((format (printf, 2, 3)));

#endif
