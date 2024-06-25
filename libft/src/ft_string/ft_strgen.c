/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:30:15 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/06/25 10:38:05 by yyyyyyyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_string.h"

char	*ft_strgen(char c, int n)
{
	char	*ret;

	ret = ft_calloc(n + 1, sizeof (char));
	ft_memset(ret, c, n);
	return (ret);
}
