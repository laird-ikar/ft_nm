/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 07:19:25 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/06/25 10:38:05 by yyyyyyyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_string.h"

char	*ft_tabjoin(char **tab, char *sep)
{
	char	*res;
	char	*tmp;

	res = ft_calloc(1, 1);
	tmp = ft_calloc(1, 1);
	while (*tab && *(tab + 1))
	{
		tmp = ft_strjoin(res, *tab);
		free (res);
		res = tmp;
		tmp = ft_strjoin(res, sep);
		free (res);
		res = tmp;
		tab++;
	}
	tmp = ft_strjoin(res, *tab);
	free (res);
	res = tmp;
	return (res);
}
