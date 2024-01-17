/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:25:13 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/28 09:49:36 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

static char	*return_value(char	*res);
static void	init(t_gnl *gnl);

char	*get_next_line(int fd)
{
	t_gnl	gnl;

	init(&gnl);
	if (fd < 0 || BUFFER_SIZE < 1 || !gnl.res || read(fd, gnl.buff, 0) < 0)
	{
		if (gnl.res)
			free(gnl.res);
		return (NULL);
	}
	while (gnl.ret > 0 && gnl.buff[gnl.i - 1] != '\n')
	{
		gnl.i = 1;
		ft_bzero(gnl.buff, BUFFER_SIZE + 1);
		while (gnl.i < BUFFER_SIZE + 1
			&& gnl.buff[gnl.i - 1] != '\n' && gnl.ret > 0)
			gnl.ret = read(fd, gnl.buff + gnl.i++, 1);
		gnl.buff[gnl.i] = '\0';
		gnl.tmp = ft_strjoin(gnl.res, gnl.buff + 1);
		free(gnl.res);
		gnl.res = gnl.tmp;
	}
	return (return_value(gnl.res));
}

static char	*return_value(char	*res)
{
	static int	for_the_bonus_pwease;

	(void) for_the_bonus_pwease;
	if (res[0] == '\0')
	{
		free(res);
		return (NULL);
	}
	return (res);
}

static void	init(t_gnl *gnl)
{
	gnl->ret = 1;
	gnl->i = 1;
	gnl->res = ft_calloc(1, 1);
	ft_bzero(gnl->buff, (BUFFER_SIZE + 2) * sizeof (char));
}
