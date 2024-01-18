/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:56:55 by bguyot            #+#    #+#             */
/*   Updated: 2024/01/17 14:59:28 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <t_nm.h>

/**
 *	@brief Initialize the main structure
 */
void	init(t_nm *nm, int argc, char *argv[]);

/**
 *	@brief Initialize the main structure
 */
void	tini(t_nm *nm);

#endif
