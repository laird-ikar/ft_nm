/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_file.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:36:13 by stage             #+#    #+#             */
/*   Updated: 2024/06/25 10:36:27 by yyyyyyyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYZE_FILE_H
# define ANALYZE_FILE_H

# include <struct.h>
# include <libft.h>
# include <enum.h>
# include <analyze_file_32bits.h>
# include <analyze_file_64bits.h>

int	analyze_file(char *file_path, t_nm nm);

#endif
