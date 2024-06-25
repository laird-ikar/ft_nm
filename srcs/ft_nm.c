/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:32:36 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/01/18 16:50:52 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <t_nm.h>
#include <init.h>
#include <libft.h>
#include <print_messages.h>

int	main(int argc, char *argv[])
{
	t_nm	nm;
	t_list	*file_ptr;
	int		error;

	init(&nm, argc, argv);
	if (nm.flags & H_FLAG)
	{
		print_help_message();
		return ((nm.flags & INVALID_FLAG) >> 7);
	}
	if (nm.flags & V_FLAG)
	{
		print_version_message();
		return ((nm.flags & INVALID_FLAG) >> 7);
	}
	file_ptr = *(nm.files);
	if (!file_ptr)
	{
		error = parse_file("a.out", nm.flags);
		tini(&nm);
		return error;
	}
	error = 0;
	while (file_ptr)
		error += parse_file(file_ptr->content);
	tini(&nm);
	return (error);
}
