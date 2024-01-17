/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:23:31 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/28 08:56:31 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_string.h"

static size_t	ft_wordlen(const char *s, char c);
static size_t	ft_wordcount(const char *s, char c);
static char		*ft_wordcpy(const char *s, size_t n);

char	**ft_split(const char *s, char c)
{
	char		**res;
	size_t		size;
	size_t		i;
	size_t		n;

	if (!s)
		return (NULL);
	size = ft_wordcount(s, c);
	res = malloc((size + 1) * sizeof(const char *));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		while (*s && *s == c)
			s++;
		n = ft_wordlen(s, c);
		res[i] = ft_wordcpy(s, n);
		if (res[i] == NULL)
			return (NULL);
		s += n;
	}
	res[size] = 0;
	return (res);
}

size_t	ft_wordlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && !(*(s + i) == c))
		i++;
	return (i);
}

size_t	ft_wordcount(const char *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = ft_wordlen(s, c);
		s += i;
		if (i)
			count++;
	}
	return (count);
}

static char	*ft_wordcpy(const char *s, size_t n)
{
	char	*dest;

	dest = malloc((n + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[n] = '\0';
	while (n--)
		dest[n] = s[n];
	return (dest);
}
