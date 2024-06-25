/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_file.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stage <***REMOVED***@***REMOVED***>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:36:13 by stage             #+#    #+#             */
/*   Updated: 2024/06/05 11:29:39 by stage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYZE_FILE_H
# define ANALYSE_FILE_H

# include <struct.h>
# include <libft.h>
# include <enum.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

void	analyze_file(char *file_path, t_nm nm);

#endif
