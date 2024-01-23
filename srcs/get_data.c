/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:54:30 by bguyot            #+#    #+#             */
/*   Updated: 2024/01/23 14:22:42 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_data.h>

char	*get_data(char *data, int offset, int len, int size)
{
	if (offset + len >= size)
		return (NULL);
	return (data + offset);
}
