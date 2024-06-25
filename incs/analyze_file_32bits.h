/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_file_32bits.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:17:40 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/06/25 10:38:05 by yyyyyyyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYZE_FILE_32BITS_H
# define ANALYZE_FILE_32BITS_H

# include <struct.h>
# include <enum.h>
# include <libft.h>
# include <quick_sort.h>

# include <sys/mman.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

int	analyze_file_32bits(t_nm *nm, char *file_path);

#endif
