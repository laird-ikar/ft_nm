/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_int.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:43:30 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/01/23 15:32:28 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_INT_H
#define READ_INT_H

#include <stdint.h>
#include <parse_file.h>

uint16_t	read_uint16(char data[], char endian);
uint32_t	read_uint32(char data[], char endian);
uint64_t	read_uint64(char data[], char endian);

#endif
