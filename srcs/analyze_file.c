/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stage <***REMOVED***@***REMOVED***>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:35:19 by stage             #+#    #+#             */
/*   Updated: 2024/06/05 11:11:38 by stage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <analyze_file.h>

void	analyze_file(char *file_path, t_nm nm)
{

	if (nm.input.files.nb_elem > 1)
		ft_printf("\n%s:\n", file_path);
}
