/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:01:53 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/01 17:31:22 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_buff.h"
#include <stdio.h>
#include <unistd.h>

t_buff	*ft_bufcat(t_buff *a, t_buff *b)
{
	t_buff	*ret;

	ret = ft_calloc(1, sizeof (t_buff));
	if (!a && !b)
	{
		ret->data = ft_memcat(NULL, NULL, 0, 0);
		ret->len = 0;
	}
	else if (!a)
	{
		ret->data = ft_memcat(NULL, b->data, 0, b->len);
		ret->len = 0 + b->len;
	}
	else if (!b)
	{
		ret->data = ft_memcat(a->data, NULL, a->len, 0);
		ret->len = a->len + 0;
	}
	else
	{
		ret->data = ft_memcat(a->data, b->data, a->len, b->len);
		ret->len = a->len + b->len;
	}
	return (ret);
}
