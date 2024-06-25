/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:19:22 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/05/02 13:50:46 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse_input.h>

static void	parse_long_option(char *option, t_input *input, t_nm nm);
static void	parse_short_options(char *options, t_input *input, t_nm nm);
void		parse_file(char *file, t_input *input);

t_input	parse_input(int argc, char *argv[], t_nm nm)
{
	t_input	input;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strncmp("--", argv[i], 2))
			parse_long_option(argv[i], &input, nm);
		else if (argv[i][0] == '-' && ft_strlen(argv[i]) > 1)
			parse_short_options(argv[i], &input, nm);
		else
			parse_file(argv[i], &input);
	}
	return (input);
}

static void	parse_long_option(char *option, t_input *input, t_nm nm)
{
	if (!ft_strcmp(option, "--debug-syms"))
		input->debug_symbols = ACTIVE;
	else if (!ft_strcmp(option, "--extern-only"))
		input->extern_only = ACTIVE;
	else if (!ft_strcmp(option, "--undefined-only"))
		input->undefined_only = ACTIVE;
	else if (!ft_strcmp(option, "--reverse-sort"))
		input->reverse_sort = ACTIVE;
	else if (!ft_strcmp(option, "--no-sort"))
		input->no_sort = ACTIVE;
	else if (!ft_strcmp(option, "--help"))
		input->help = ACTIVE;
	else
	{
		ft_printf("ft_nm: unrecognized option '%s'", option);
		print_help();
		ft_error(nm, INVALID_FLAG);
	}
}

static void	parse_short_options(char *options, t_input *input, t_nm nm)
{
	int	i;

	i = 1;
	while (options[i])
	{
		if (options[i] == 'a')
			input->debug_symbols = ACTIVE;
		else if (options[i] == 'g')
			input->extern_only = ACTIVE;
		else if (options[i] == 'u')
			input->undefined_only = ACTIVE;
		else if (options[i] == 'r')
			input->reverse_sort = ACTIVE;
		else if (options[i] == 'p')
			input->no_sort = ACTIVE;
		else if (options[i] == 'h')
			input->help = ACTIVE;
		else
		{
			ft_printf("ft_nm: unrecognized option '%c'", options[i]);
			print_help();
			ft_error(nm, INVALID_FLAG);
		}
	}
}

void	parse_file(char *file, t_input *input)
{
	(void) file;
	(void) input;
}
