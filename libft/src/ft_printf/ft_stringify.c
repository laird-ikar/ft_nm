/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:42:03 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/06/25 10:38:05 by yyyyyyyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/_ft_printf.h"

/*
 *	ft_stringify
 *
 *	puts back all the tokens in a string
 *
 *	token:
 *		token list to transform in string
 */
t_buff	*ft_stringify(t_list *token)
{
	t_buff	*ret;
	t_buff	*tmp;

	ret = NULL;
	while (token)
	{
		tmp = ret;
		ret = ft_bufcat(tmp, ((t_buff *) token->content));
		ft_bufclear(tmp);
		token = token->next;
	}
	return (ret);
}
