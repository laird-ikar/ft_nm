/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:22:19 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/06/25 10:38:06 by yyyyyyyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_list.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !(*lst))
		return ;
	if ((*lst)->next)
		ft_lstclear(&(*lst)->next, del);
	if (del)
		del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
