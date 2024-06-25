/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:00:17 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/06/21 14:01:13 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <quick_sort.h>

static
void swap(t_symbol* a, t_symbol* b)
{
	t_symbol temp = *a;
	*a = *b;
	*b = temp;
}

// Partition function
static
int partition(t_symbol *symbols, int low, int high, int (*f_comp)(t_symbol, t_symbol))
{
	t_symbol	pivot = symbols[low];
	int			i = low;
	int			j = high;

	while (i < j) {
		while (f_comp(symbols[i], pivot) <= 0 && i <= high - 1) {
			i++;
		}
		while (f_comp(symbols[j], pivot) > 0 && j >= low + 1) {
			j--;
		}
		if (i < j) {
			swap(&symbols[i], &symbols[j]);
		}
	}
	swap(&symbols[low], &symbols[j]);
	return j;
}

void quick_sort(t_symbol *symbols, int low, int high, int (*f_comp)(t_symbol, t_symbol))
{
	if (low < high) {
		int partitionIndex = partition(symbols, low, high, f_comp);
		quick_sort(symbols, low, partitionIndex - 1, f_comp);
		quick_sort(symbols, partitionIndex + 1, high, f_comp);
	}
}
