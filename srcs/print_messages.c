/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:09:00 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/01/23 15:35:50 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <print_messages.h>

const char	*g_implementation_text[] = {
	[OK] = "",
	[NOT_IMPLEMENTED] = " (not implemented)"
};

void	print_help_message(void)
{
	ft_printf("Usage: ft_nm [option]+ [file]+\n");
	ft_printf("\tList symbols in [file]+ (a.out by default).\n");
	ft_printf("\tThe options are:\n");
	ft_printf(
		"\t\t-a,\t--debug-syms\t\tDisplay debugger-only symbols%s\n",
		g_implementation_text[A_IS_IMPLEMENTED]
	);
	ft_printf(
		"\t\t-g,\t--extern-only\t\tDisplay only external symbols%s\n",
		g_implementation_text[G_IS_IMPLEMENTED]
	);
	ft_printf(
		"\t\t-p,\t--no-sort\t\tDo not sort the symbols%s\n",
		g_implementation_text[P_IS_IMPLEMENTED]
	);
	ft_printf(
		"\t\t-r,\t--reverse-sort\t\tReverse the sense of the sort%s\n",
		g_implementation_text[R_IS_IMPLEMENTED]
	);
	ft_printf(
		"\t\t-u,\t--undefined-only\tDisplay only undefined symboles%s\n",
		g_implementation_text[U_IS_IMPLEMENTED]
	);
	ft_printf(
		"\t\t-h,\t--help\t\t\tDisplay this information%s\n",
		g_implementation_text[H_IS_IMPLEMENTED]
	);
	ft_printf(
		"\t\t-V,\t--version\t\tDisplay this program's version number%s\n",
		g_implementation_text[R_IS_IMPLEMENTED]
	);
	print_supported_target_message();
	ft_printf("Report bugs to <%s>.\n", REPORT_ADDRESS);
}

void	print_supported_target_message(void)
{
	ft_printf("nm: supported targets:");
	ft_printf("\n");
}

void	print_version_message(void)
{
	ft_printf("ft_nm 0.1\n");
}
