/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stage <***REMOVED***@***REMOVED***>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:19:22 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/06/04 17:58:42 by stage            ###   ########.fr       */
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

	i = 0;
	input = nm.input;
	while (++i < argc)
	{
		if (!ft_strcmp("--", argv[i]))
			break;
		if (!ft_strncmp("--", argv[i], 2))
			parse_long_option(argv[i], &input, nm);
		else if (argv[i][0] == '-' && ft_strlen(argv[i]) > 1)
			parse_short_options(argv[i], &input, nm);
		else
			parse_file(argv[i], &input);
	}
	while (++i < argc)
			parse_file(argv[i], &input);
	if (input.files.nb_elem == 0)
		parse_file("a.out", &input);
	return (input);
}

// TODO: not only check for exact
// match but also start (i.e. --de == --d == --debyg-syms)
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
		ft_printf("ft_nm: unrecognized option '%s'\n", option);
		print_help();
		ft_error(nm, INVALID_FLAG);
	}
}

static void	parse_short_options(char *options, t_input *input, t_nm nm)
{
	int	i;

	i = 0;
	while (options[++i])
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
			ft_printf("ft_nm: invalid option -- '%c'\n", options[i]);
			print_help();
			ft_error(nm, INVALID_FLAG);
		}
	}
}

void	parse_file(char *file, t_input *input)
{
	void	*temporary_ptr;

	if (!input->files.nb_allocated)
	{
		input->files.data = ft_calloc(1, sizeof (char *));
		input->files.nb_allocated = 1;
	}
	else if (input->files.nb_allocated == input->files.nb_elem)
	{
		temporary_ptr = input->files.data;
		input->files.nb_allocated *= 2;
		input->files.data
			= ft_calloc(input->files.nb_allocated, sizeof (char *));
		ft_memcpy(input->files.data, temporary_ptr, input->files.nb_elem);
		free(temporary_ptr);
	}
	input->files.data[input->files.nb_elem++] = ft_strdup(file);
}
