/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:24:01 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/06/25 10:38:05 by yyyyyyyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_string.h"

static void		*ft_copy(char *dst, const char *src, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	if (!dst)
		return (0);
	if (!src)
		return (ft_strlcpy(dst, "", dstsize));
	srclen = ft_strlen(src);
	if (srclen + 1 < dstsize)
	{
		ft_copy(dst, src, srclen + 1);
	}
	else if (dstsize != 0)
	{
		ft_copy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (srclen);
}

static void	*ft_copy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst != src)
	{
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
