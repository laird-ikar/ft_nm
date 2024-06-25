/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:50:39 by ***REMOVED***            #+#    #+#             */
/*   Updated: 2024/01/18 12:11:10 by ***REMOVED***           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <init.h>

/**
 *	@brief	Parse the flags declared via a --flag-name format
 *		Unknown flags are interpreted as a --help
 */
static
uint8_t	parse_word_flag(char *flag);

/**
 *	@brief	Parse the flags declared via a -abc format
 *		Unknown flags are interpreted as a -h
 */
static
uint8_t	parse_letter_flags(char *flag);

void	init(t_nm *nm, int argc, char *argv[])
{
	int	i;

	nm->files = ft_calloc(1, sizeof (t_list));
	nm->flags = NO_FLAG;
	i = 0;
	while(++i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == '-')
				nm->flags |= parse_word_flag(argv[i] + 2);
			else
				nm->flags |= parse_letter_flags(argv[i]);
		}
		else
			ft_lstadd_back(nm->files, ft_lstnew(ft_strdup(argv[i])));
	}
}

void	tini(t_nm *nm)
{
	ft_lstclear(nm->files, free);
	free(nm->files);
}

static
uint8_t	parse_word_flag(char *flag_name)
{
	if (!ft_strcmp(flag_name, "version"))
		return V_FLAG;
	if (!ft_strcmp(flag_name, "debug-syms"))
		return A_FLAG;
	if (!ft_strcmp(flag_name, "extern-only"))
		return G_FLAG;
	if (!ft_strcmp(flag_name, "undefined-only"))
		return U_FLAG;
	if (!ft_strcmp(flag_name, "reverse-sort"))
		return R_FLAG;
	if (!ft_strcmp(flag_name, "no-sort"))
		return P_FLAG;
	if (!ft_strcmp(flag_name, "help"))
		return H_FLAG;
	return H_FLAG | INVALID_FLAG;
}

static
uint8_t parse_letter_flags(char *letter_flags)
{
	uint8_t	flags;

	flags = 0;
	while(*(++letter_flags))
	{
		if (*letter_flags == 'a')
		{
			flags |= A_FLAG;
			continue;
		}
		if (*letter_flags == 'g')
		{
			flags |= G_FLAG;
			continue;
		}
		if (*letter_flags == 'u')
		{
			flags |= U_FLAG;
			continue;
		}
		if (*letter_flags == 'r')
		{
			flags |= R_FLAG;
			continue;
		}
		if (*letter_flags == 'p')
		{
			flags |= P_FLAG;
			continue;
		}
		if (*letter_flags == 'V')
		{
			flags |= V_FLAG;
			continue;
		}
		if (*letter_flags == 'h')
		{
			flags |= H_FLAG;
			continue;
		}
		flags |= H_FLAG | INVALID_FLAG;
	}
	return flags;
}
