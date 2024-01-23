/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:32:36 by bguyot            #+#    #+#             */
/*   Updated: 2024/01/22 10:25:00 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <t_nm.h>
#include <init.h>
#include <libft.h>
#include <print_messages.h>
#include <parse_file.h>
#include <libft.h>

static
int	parse_files(t_nm *nm);

int	main(int argc, char *argv[])
{
	t_nm	nm;
	int		error;

	init(&nm, argc, argv);
	if (nm.flags & H_FLAG)
	{
		print_help_message();
		tini(&nm);
		return ((nm.flags & INVALID_FLAG) >> 7);
	}
	if (nm.flags & V_FLAG)
	{
		print_version_message();
		tini(&nm);
		return ((nm.flags & INVALID_FLAG) >> 7);
	}
	error = parse_files(&nm);
	tini(&nm);
	return (error);
}

int	parse_files(t_nm *nm)
{
	int		error;
	t_list	*file_ptr;

	file_ptr = *(nm->files);
	if (!file_ptr)
	{
		error = parse_file("a.out", nm->flags, 0);
		return error;
	}
	error = 0;
	while (file_ptr)
	{
		error += parse_file(file_ptr->content, nm->flags, ft_lstsize(*(nm->files)) > 1);
		file_ptr = file_ptr->next;
	}
	return error;
}
