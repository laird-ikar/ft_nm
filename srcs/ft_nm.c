/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stage <***REMOVED***@***REMOVED***>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:42:04 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/06/04 17:25:08 by stage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

#ifdef FT_DEBUG_MODE
void debug(t_nm nm)
{
	ft_printf("FLAGS: debug_symbols: %d, ", nm.input.debug_symbols);
	ft_printf("extern_only: %d, ", nm.input.extern_only);
	ft_printf("undefined_only: %d, ", nm.input.undefined_only);
	ft_printf("reverse_sort: %d, ", nm.input.reverse_sort);
	ft_printf("no_sort: %d, ", nm.input.no_sort);
	ft_printf("help: %d\n", nm.input.help);
	ft_printf("FILES: ");
	for (int i = 0 ; i < nm.input.files.nb_elem ; i++)
		ft_printf("%s, ", nm.input.files.data[i]);
	ft_printf("\n");
}
#endif

int	main(int argc, char *argv[])
{
	t_nm	nm;

	nm = init();
	nm.input = parse_input(argc, argv, nm);
	#ifdef FT_DEBUG_MODE
	debug(nm);
	#endif
	tini(nm);
	return (0);
}
