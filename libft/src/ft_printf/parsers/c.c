/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:02:03 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2022/12/02 17:25:34 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/_ft_printf.h"

t_buff	*c(va_list lst, t_flag *flag)
{
	t_buff	*ret;
	char	data;

	ret = ft_calloc(1, sizeof (t_buff));
	data = va_arg(lst, int);
	ret->len = 1;
	ret->data = ft_strndup(&data, 1);
	return (ret);
	(void) flag;
}
