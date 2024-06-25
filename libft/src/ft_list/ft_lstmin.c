/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:26:54 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2022/12/06 09:48:35 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_list.h"

int	ft_lstminint(t_list *lst)
{
	int	min;

	min = 2147483647;
	while (lst)
	{
		if (min > *(int *)lst->content)
		{
			min = *(int *)lst->content;
		}
		lst = lst->next;
	}
	return (min);
}
