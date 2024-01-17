/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:22:10 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/28 09:44:40 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARR_H
# define FT_ARR_H

# include <stddef.h>
# include "ft_math.h"

/* Sort the the given array of size size */
void	ft_sort_int_tab(int *tab, int size);

/* Return the minimum of the array */
int		ft_tabmin(int *tab, size_t size);

/* Return the minimum of the array */
int		ft_tabmax(int *tab, size_t size);

/* Return the med of the array */
int		ft_tabmed(int *tab, int size);

#endif
