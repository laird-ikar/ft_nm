/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_target.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:40:21 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/01/18 16:53:10 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TARGET_H
# define T_TARGET_H

# include <stddef.h>

typedef struct {
	char	name[64];
}	t_target;

const size_t	g_nb_supported_targets = 0;
const t_target	g_supported_target[] = {};

#endif
