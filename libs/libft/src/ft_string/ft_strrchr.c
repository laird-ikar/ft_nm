/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:24:19 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/28 08:55:45 by bguyot           ###   ########.fr       */
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
