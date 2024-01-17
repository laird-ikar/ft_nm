/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnnext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:21:56 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/28 09:02:18 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_list.h"

t_list	*ft_lstnnext(t_list *lst, size_t n)
{
	if (!lst)
		return (NULL);
	while (n-- && lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
