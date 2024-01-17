/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:22:11 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/28 09:02:51 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_list.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	if (!lst)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new_lst;
	else
		*lst = new_lst;
}
