/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:42:04 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/07/02 12:52:44 by yyyyyyyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

#ifdef FT_DEBUG_MODE
static void debug(t_nm nm)
{
	int i;
	ft_dprintf(2, "\033[1;33m");
	ft_dprintf(2, "FLAGS: debug_symbols: %d, ", nm.input.debug_symbols);
	ft_dprintf(2, "extern_only: %d, ", nm.input.extern_only);
	ft_dprintf(2, "undefined_only: %d, ", nm.input.undefined_only);
	ft_dprintf(2, "reverse_sort: %d, ", nm.input.reverse_sort);
	ft_dprintf(2, "no_sort: %d, ", nm.input.no_sort);
	ft_dprintf(2, "help: %d\n", nm.input.help);
	ft_dprintf(2, "%d FILE(S): ", nm.input.files.nb_elem);
	i = 0;
	while (i < nm.input.files.nb_elem)
	{
		ft_dprintf(2, "(%d)", i);
		ft_dprintf(2, "%s, ", nm.input.files.data[i]);
		i++;
	}
	ft_dprintf(2, "\n");
	ft_dprintf(2, "\033[0m");
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
