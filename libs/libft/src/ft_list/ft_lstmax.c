/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:26:54 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2022/11/28 09:02:26 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_list.h"

int	ft_lstmaxint(t_list *lst)
{
	int	max;

	max = -2147483648;
	while (lst)
	{
		if (max < *(int *)lst->content)
		{
			max = *(int *)lst->content;
		}
		lst = lst->next;
	}
	return (max);
}
