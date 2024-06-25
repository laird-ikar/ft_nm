/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:54:30 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/01/23 14:22:42 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_data.h>

char	*get_data(char *data, int offset, int len, int size)
{
	if (offset + len >= size)
		return (NULL);
	return (data + offset);
}
