/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:42:04 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/06/21 15:50:18 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

#ifdef FT_DEBUG_MODE
static void debug(t_nm nm)
{
	int i;
	ft_printf("\033[1;33m");
	ft_printf("FLAGS: debug_symbols: %d, ", nm.input.debug_symbols);
	ft_printf("extern_only: %d, ", nm.input.extern_only);
	ft_printf("undefined_only: %d, ", nm.input.undefined_only);
	ft_printf("reverse_sort: %d, ", nm.input.reverse_sort);
	ft_printf("no_sort: %d, ", nm.input.no_sort);
	ft_printf("help: %d\n", nm.input.help);
	ft_printf("%d FILE(S): ", nm.input.files.nb_elem);
	i = 0;
	while (i < nm.input.files.nb_elem)
	{
		ft_printf("(%d)", i);
		ft_printf("%s, ", nm.input.files.data[i]);
		i++;
	}
	ft_printf("\n");
	ft_printf("\033[0m");
}
#endif

int	main(int argc, char *argv[])
{
	t_nm	nm;
	int		i;
	int		ret;

	ret = 0;
	nm = init();
	nm.input = parse_input(argc, argv, nm);
	#ifdef FT_DEBUG_MODE
	debug(nm);
	#endif
	if (nm.input.help)
		print_help();
	else
	{
		i = 0;
		while (i < nm.input.files.nb_elem)
		{
			ret += analyze_file(nm.input.files.data[i++], nm);
		}
	}
	tini(nm);
	return (ret);
}
