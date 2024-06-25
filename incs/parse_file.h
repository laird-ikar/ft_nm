/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:59:17 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/01/18 18:03:01 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FILE_H
# define PARSE_FILE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>

int	parse_file(char *path, uint8_t flags, int has_to_print_name);

#endif
