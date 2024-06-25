/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 07:58:18 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/06/25 10:38:06 by yyyyyyyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_buff.h"

void	ft_bufclear(void *buf)
{
	if (!buf)
		return ;
	if (((t_buff *) buf)->data)
		free(((t_buff *) buf)->data);
	((t_buff *) buf)->data = NULL;
	((t_buff *) buf)->len = 0;
	free(buf);
}
