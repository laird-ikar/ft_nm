/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:30:15 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/02 16:34:23 by bguyot           ###   ########.fr       */
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
