/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:50:31 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/06/25 10:38:05 by yyyyyyyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/_ft_printf.h"

t_buff	*u(va_list lst, t_flag *flag)
{
	t_buff			*ret;
	unsigned int	data;
	char			*tmp;

	ret = ft_calloc(1, sizeof (t_buff));
	data = va_arg(lst, unsigned);
	ret->data = ft_utoa(data);
	update_zero_flag(flag, ret);
	if (data == 0 && flag->precision == 0)
	{
		tmp = ft_strdup("");
		free(ret->data);
		ret->data = tmp;
	}
	ret->len = ft_strlen(ret->data);
	return (ret);
}
