/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:24:19 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/06/25 10:38:05 by yyyyyyyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	*tmp;

	tmp = NULL;
	while (*s)
	{
		if (*s == c)
			tmp = (unsigned char *) s;
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return ((char *) tmp);
}
