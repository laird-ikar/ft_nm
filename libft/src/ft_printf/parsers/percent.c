/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:50:15 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/06 10:03:14 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/_ft_printf.h"

t_buff	*percent(va_list lst, t_flag *flag)
{
	t_buff	*ret;
	char	*data;

	ret = ft_calloc(1, sizeof (t_buff));
	data = "%";
	ret->data = ft_strdup(data);
	ret->len = ft_strlen(ret->data);
	return (ret);
	(void) lst;
	(void) flag;
}
