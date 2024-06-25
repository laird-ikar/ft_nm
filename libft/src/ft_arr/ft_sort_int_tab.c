/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:36:33 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2022/11/28 08:28:56 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_arr.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size - 1 - j)
		{
			if (tab [i] > tab[i + 1])
			{
				temp = tab [i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
		j++;
	}
}
