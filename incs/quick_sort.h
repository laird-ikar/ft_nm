/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:00:34 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/06/21 14:01:21 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_SORT_H
# define QUICK_SORT_H

# include <enum.h>
# include <struct.h>

void quick_sort(t_symbol *symbols, int low, int high, int (*f_comp)(t_symbol, t_symbol));

#endif
