/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:03:34 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/06 09:24:55 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/_ft_printf.h"

/*
 *	[padding spaces][sign symbole][0 padding][mainstr][left padding space]
 *			4				3			2		1			0
 */
void	apply_width(t_buff *buff, t_flag *flag)
{
	t_buff	segment[5];
	t_buff	ret;
	int		padding_space;

	segment[1].data = ft_memdup(buff->data, buff->len);
	segment[1].len = buff->len;
	padding_space = ft_max(
			0,
			flag->min_width - buff->len - ft_abs(flag->sign) - flag->zero_prec
			);
	create_padding(segment, flag, padding_space);
	create_sign(segment, flag);
	ret = concat_segment(segment);
	free(buff->data);
	buff->data = ret.data;
	buff->len = ret.len;
}

t_buff	concat_segment(t_buff segment[5])
{
	t_buff	ret;
	char	*tmp;
	int		i;

	ret.data = NULL;
	ret.len = 0;
	i = 5;
	while (i--)
	{
		tmp = ft_memcat(ret.data, segment[i].data, ret.len, segment[i].len);
		free(ret.data);
		ret.data = tmp;
		ret.len += segment[i].len;
		free(segment[i].data);
	}
	return (ret);
}

void	create_padding(t_buff segment[5], t_flag *flag, int padding_space)
{
	ft_bzero(&segment[0], sizeof (t_buff));
	ft_bzero(&segment[2], sizeof (t_buff));
	ft_bzero(&segment[4], sizeof (t_buff));
	if (flag->padding_type == 0)
	{
		segment[4].data = ft_strgen(' ', padding_space);
		segment[4].len = ft_strlen(segment[4].data);
	}
	else if (flag->padding_type == '-')
	{
		segment[0].data = ft_strgen(' ', padding_space);
		segment[0].len = ft_strlen(segment[0].data);
	}
	else if (flag->padding_type == '0')
	{
		segment[2].data = ft_strgen('0', padding_space);
		segment[2].len = ft_strlen(segment[2].data);
	}
	if (flag->zero_prec > 0)
	{
		segment[2].data = ft_strgen('0', flag->zero_prec);
		segment[2].len = ft_strlen(segment[2].data);
	}
}

void	create_sign(t_buff segment[5], t_flag *flag)
{
	segment[3].data = NULL;
	segment[3].len = 0;
	if (flag->sign)
	{
		if (flag->sign < 0)
			segment[3].data = ft_strgen('-', 1);
		else if (flag->positive_sign)
			segment[3].data = ft_strgen(flag->positive_sign, 1);
		segment[3].len = ft_strlen(segment[3].data);
	}
}
