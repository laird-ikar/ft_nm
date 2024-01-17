/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:38:26 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/05 08:41:14 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_buff.h"

t_buff	*ft_bufcpy(t_buff *src)
{
	t_buff	*ret;

	ret = ft_calloc(1, sizeof (t_buff));
	ft_memcpy(ret->data, src->data, src->len);
	ret->len = src->len;
	return (ret);
}
