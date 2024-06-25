/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:38:43 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/01/23 16:19:39 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <read_int.h>

uint16_t	read_uint16(char data[], char endian)
{
	if (endian == FT_BIG_ENDIAN)
	{
		return ((uint16_t) data[0] & 0xFF) << (8 * 1) |
			((uint16_t) data[1] & 0xFF);
	}
	else if (endian == FT_SMALL_ENDIAN)
	{
		return ((uint16_t) data[1] & 0xFF) << (8 * 1) |
			((uint16_t) data[0] & 0xFF);
	}
	ft_printf("Warning: endian is invalid.");
	return ((uint16_t) -1);
}

uint32_t	read_uint32(char data[], char endian)
{
	if (endian == FT_BIG_ENDIAN)
	{
		return ((uint32_t) data[0] & 0xFF) << (8 * 3) |
			((uint32_t) data[1] & 0xFF) << (8 * 2) |
			((uint32_t) data[2] & 0xFF) << (8 * 1) |
			((uint32_t) data[3] & 0xFF);
	}
	else if (endian == FT_SMALL_ENDIAN)
	{
		return ((uint32_t) data[3] & 0xFF) << (8 * 3) |
			((uint32_t) data[2] & 0xFF) << (8 * 2) |
			((uint32_t) data[1] & 0xFF) << (8 * 1) |
			((uint32_t) data[0] & 0xFF);
	}
	ft_printf("Warning: endian is invalid.");
	return ((uint32_t) -1);
}

uint64_t	read_uint64(char data[], char endian)
{
	if (endian == FT_BIG_ENDIAN)
	{
		return ((uint64_t) data[0] & 0xFF) << (8 * 7) |
			((uint64_t) data[1] & 0xFF) << (8 * 6) |
			((uint64_t) data[2] & 0xFF) << (8 * 5) |
			((uint64_t) data[3] & 0xFF) << (8 * 4) |
			((uint64_t) data[4] & 0xFF) << (8 * 3) |
			((uint64_t) data[5] & 0xFF) << (8 * 2) |
			((uint64_t) data[6] & 0xFF) << (8 * 1) |
			((uint64_t) data[7] & 0xFF);
	}
	else if (endian == FT_SMALL_ENDIAN)
	{
		return ((uint64_t) data[7] & 0xFF) << (8 * 7) |
			((uint64_t) data[6] & 0xFF) << (8 * 6) |
			((uint64_t) data[5] & 0xFF) << (8 * 5) |
			((uint64_t) data[4] & 0xFF) << (8 * 4) |
			((uint64_t) data[3] & 0xFF) << (8 * 3) |
			((uint64_t) data[2] & 0xFF) << (8 * 2) |
			((uint64_t) data[1] & 0xFF) << (8 * 1) |
			((uint64_t) data[0] & 0xFF);
	}
	ft_printf("Warning: endian is invalid.");
	return ((uint64_t) -1);
}
