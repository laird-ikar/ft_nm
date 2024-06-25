/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:21:40 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/06/25 10:38:05 by yyyyyyyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/_ft_printf.h"

t_buff	*f(va_list lst, t_flag *flag)
{
	double	data;
	t_buff	*ret;

	ret = ft_calloc(1, sizeof (t_buff));
	ret->data = ft_strdup("(not implemented)");
	ret->len = ft_strlen(ret->data);
	data = va_arg(lst, double);
	return (ret);
	(void) flag;
	(void) data;
}
