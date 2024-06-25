/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:55:21 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/01/18 18:10:57 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse_file.h>

int	parse_file(char *path, uint8_t flags, int has_to_print_name)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("ft_nm: ");
		perror(path);
		return (1);
	}
	close(fd);
	return(0);
}
