/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:27:34 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/06/25 10:38:05 by yyyyyyyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/_ft_printf.h"

void	update_flag(t_flag *flag, int data, t_buff *ret)
{
	flag->sign = ft_sign(data);
	if (!data)
		flag->sign = 1;
	if (data >= 0 && !flag->positive_sign)
		flag->sign = 0;
	update_zero_flag(flag, ret);
}

void	update_zero_flag(t_flag *flag, t_buff *ret)
{
	if (flag->precision >= 0)
	{
		if (flag->padding_type == '0')
			flag->padding_type = 0;
		flag->zero_prec = flag->precision - ft_strlen(ret->data);
		if (flag->zero_prec < 0)
			flag->zero_prec = 0;
	}
}
