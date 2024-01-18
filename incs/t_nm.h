/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_nm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:39:27 by bguyot            #+#    #+#             */
/*   Updated: 2024/01/18 12:10:29 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_NM_H
# define T_NM_H

# include <stdint.h>
# include <libft.h>

typedef struct
{
	uint8_t	flags;
	t_list	**files;
}	t_nm;

enum
{
	NO_FLAG,
	A_FLAG = 1 << 0,
	G_FLAG = 1 << 1,
	U_FLAG = 1 << 2,
	R_FLAG = 1 << 3,
	P_FLAG = 1 << 4,
	H_FLAG = 1 << 5,
	V_FLAG = 1 << 6,
	INVALID_FLAG = 1 << 7,
};

#endif
