/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:17:00 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/28 08:36:40 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_cast.h"

static int	ft_digits(unsigned long nb, int base);
static int	is_valid(char *base);

char	*ft_ultoa_base(unsigned long nb, char *base)
{
	int		base_size;
	int		i;
	int		res_size;
	char	*res;

	base_size = is_valid(base);
	res_size = ft_digits(nb, base_size);
	res = malloc(sizeof(*res) * (res_size + 1));
	i = res_size - 1;
	while (i >= 0)
	{
		res[i] = base[nb % base_size];
		nb /= base_size;
		i--;
	}
	res[res_size] = '\0';
	return (res);
}

static int	ft_digits(unsigned long nb, int base)
{
	int	i;

	i = 1;
	while (nb >= (unsigned long) base)
	{
		nb /= base;
		i++;
	}
	return (i);
}

static int	is_valid(char *base)
{
	int	size;
	int	j;

	j = 0;
	size = 0;
	while (base[size])
	{
		if (base[size] == '+' || base[size] == '-'
			|| base[size] == ' ' || base[size] == '\n' || base[size] == '\f'
			|| base[size] == '\r' || base[size] == '\t' || base[size] == '\v')
			return (0);
		j = 0;
		while (j < size)
		{
			if (base[size] == base [j])
				return (0);
			j++;
		}
		size++;
	}
	if (size >= 2)
		return (size);
	else
		return (0);
}
