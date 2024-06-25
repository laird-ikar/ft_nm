/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:07:56 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/06/25 10:38:05 by yyyyyyyy         ###   ########.fr       */
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
