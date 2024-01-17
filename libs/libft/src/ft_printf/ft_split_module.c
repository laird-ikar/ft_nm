/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_module.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:41:42 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/01 17:43:22 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/_ft_printf.h"

/*
 *	ft_split_module:
 *
 *	returns a pointer to a list of format tokens
 *
 *	format:
 *		the format string to tokenise
 *
 *	e.g.
 *		ft_format:		"bla bla bla %s %-3d bla bla%%%x%%"
 *		returned value:	["bla bla bla "]->["%s"]->[" "]->["%-3d"]->[" bla bla"]
 *							->["%%"]->["%x"]->["%%"]
 */
t_list	*ft_split_module(const char *beg_str)
{
	const char	*end_str;
	t_list		*ret;
	int			in_flag;

	ret = NULL;
	end_str = beg_str;
	in_flag = *beg_str == '%';
	while (*end_str)
	{
		if (
			(in_flag && end_str != beg_str && is_conversion(*end_str))
			|| (!in_flag && (*(end_str + 1) == '%' || *(end_str + 1) == '\0'))
		)
		{
			add_buffer_to_list(&ret, beg_str, end_str);
			in_flag = *(end_str + 1) == '%';
			beg_str = end_str + 1;
		}
		end_str++;
	}
	return (ret);
}

void	add_buffer_to_list(
			t_list **lst,
			const char *beg_str,
			const char *end_str
			)
{
	t_buff	*buf_to_add;
	char	*tmp;

	tmp = ft_strndup(beg_str, end_str - beg_str + 1);
	buf_to_add = ft_atobuf(tmp);
	free(tmp);
	ft_lstadd_back(lst, ft_lstnew(buf_to_add));
}
