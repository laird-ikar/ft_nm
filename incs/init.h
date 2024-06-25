/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:07:56 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/05/01 16:48:10 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <struct.h>
# include <libft.h>
# include <array_2d.h>

/**
 *	@brief		Create a new `t_nm` structure,
 					initializing all field that must be initialized
 *	@returns	A new `t_nm`, ready to be used
 */
t_nm	init(void);

/**
 *	@brief		Free all allocated memory of a `t_nm`.
 */
void	tini(t_nm nm);

#endif
