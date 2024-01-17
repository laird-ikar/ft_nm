/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:53:43 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/05 08:55:19 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_memory.h"

void	*ft_memdup(void *src, size_t len)
{
	void	*ret;

	ret = ft_calloc(len, sizeof (char));
	ft_memcpy(ret, src, len);
	return (ret);
}
