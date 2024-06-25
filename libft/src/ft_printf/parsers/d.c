/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:48:18 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/06/25 10:38:05 by yyyyyyyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/_ft_printf.h"

t_buff	*d(va_list lst, t_flag *flag)
{
	t_buff	*ret;
	int		data;
	char	*tmp;

	ret = ft_calloc(1, sizeof (t_buff));
	data = va_arg(lst, int);
	ret->data = ft_itoa(data);
	if (data < 0)
	{
		tmp = ft_substr(ret->data, 1, ft_strlen(ret->data) - 1);
		free(ret->data);
		ret->data = tmp;
	}
	update_flag(flag, data, ret);
	if (data == 0 && flag->precision == 0)
	{
		tmp = ft_strdup("");
		free(ret->data);
		ret->data = tmp;
	}
	ret->len = ft_strlen(ret->data);
	return (ret);
}
