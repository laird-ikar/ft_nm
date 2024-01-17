/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:47:50 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/06 09:53:42 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/_ft_printf.h"

int	ft_printf(const char *ft_format, ...)
{
	t_list	*module;
	t_buff	*out;
	int		ret;
	va_list	args;

	if (!ft_strlen(ft_format))
		return (0);
	va_start(args, ft_format);
	module = ft_split_module(ft_format);
	ft_parse(module, args);
	out = ft_stringify(module);
	ft_lstclear(&module, *ft_bufclear);
	write(1, out->data, out->len);
	ret = out->len;
	ft_bufclear(out);
	va_end(args);
	return (ret);
}
