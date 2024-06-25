/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_file_64bits.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:40:25 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/06/21 16:06:54 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYZE_FILE_64BITS_H
# define ANALYZE_FILE_64BITS_H

# include <struct.h>
# include <enum.h>
# include <libft.h>
# include <quick_sort.h>

# include <sys/mman.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

int	analyze_file_64bits(t_nm *nm, char *file_path);

#endif
