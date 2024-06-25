/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:19:22 by yyyyyyyy          #+#    #+#             */
/*   Updated: 2024/06/25 10:38:06 by yyyyyyyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse_input.h>

static void	parse_long_option(char *option, t_input *input, t_nm nm);
static void	parse_short_options(char *options, t_input *input, t_nm nm);
static void	parse_file(char *file, t_input *input, t_nm nm);

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
			parse_file(argv[i], &input, nm);
	}
	while (++i < argc)
			parse_file(argv[i], &input, nm);
	if (!input.files.nb_elem)
		parse_file("a.out", &input, nm);
	return (input);
}

static int	is_start(char *needle, char *hay)
{
	int	i;

	i = 0;
	while (needle[i])
	{
		if (needle[i] != hay[i])
			return (0);
		i++;
	}
	return (1);
}

static void	parse_long_option(char *option, t_input *input, t_nm nm)
{
	if (is_start(option + 2, "debug-syms"))
		input->debug_symbols = ACTIVE;
	else if (is_start(option + 2, "extern-only"))
		input->extern_only = ACTIVE;
	else if (is_start(option + 2, "undefined-only"))
		input->undefined_only = ACTIVE;
	else if (is_start(option + 2, "reverse-sort"))
		input->reverse_sort = ACTIVE;
	else if (is_start(option + 2, "no-sort"))
		input->no_sort = ACTIVE;
	else if (is_start(option + 2, "help"))
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

static void	parse_file(char *file, t_input *input, t_nm nm)
{
	void	*tmp;

	if (!input->files.nb_allocated)
	{
		input->files.data = ft_calloc(1, sizeof (char *));
		input->files.nb_allocated = 1;
	}
	else if (input->files.nb_elem == input->files.nb_allocated)
	{
		tmp = malloc(input->files.nb_allocated * 2 * sizeof (char *));
		if (!tmp)
			ft_error(nm, FAILED_ALLOCATION);
		ft_memcpy(tmp, input->files.data, input->files.nb_elem * sizeof (char *));
		free(input->files.data);
		input->files.data = tmp;
		input->files.nb_allocated *= 2;
	}
	input->files.data[(input->files.nb_elem)++] = ft_strdup(file);
}
