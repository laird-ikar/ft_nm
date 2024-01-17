/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:26:05 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/02 16:35:06 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>
# include <stdlib.h>
# include "ft_memory.h"

/* Join all the char* of tab in one big string, separating them with sep */
char	*ft_tabjoin(char **tab, char *sep);
/* Compare the strings s1 and s2, char by char
** and return the first diffrence (is ascii value) */
int		ft_strcmp(const char *s1, const char *s2);

/* Compare the at most n first chars of s1 and s2
** and return the first diffrence (is ascii value) */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* Compare first chars of s1 and s2
** and return the first diffrence (is ascii value) */
int		ft_strcmp(const char *s1, const char *s2);

/* Apply the function f to each char of s */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/* Return the size of s */
size_t	ft_strlen(const char *s);

/* Copy at most dstsize - 1 chars from src to dst,
** \0 terminate dst and return the original size of src */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/* Concatenate dst and src, for at most dstsize char and return
** the initial size of dst + the size of src */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/* Return the address of the first occurence of c in the string pointed by s */
char	*ft_strchr(const char *s, int c);

/* Return the address of the last occurence of c in the string pointed by s */
char	*ft_strrchr(const char *s, int c);

/* Return the address of the first occurence of needle in haystack */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/* Allocate and return a copy of s1 */
char	*ft_strdup(const char *s1);

/* Allocate and return a null terminated string of the n first char of s1 */
char	*ft_strndup(const char *src, size_t n);

/* Allocate and return the substring starting at the index start
** of lenght len (NULL if allocation fails) */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* Allocate and return the concatenation of s1 and s2
** (NULL if allocation fails) */
char	*ft_strjoin(char const *s1, char const *s2);

/* Allocate and return a substring of s1
** without begining and end char that are present in set
** (NULL if allocation fails) */
char	*ft_strtrim(char const *s1, char const *set);

/* Allocate and return a string of f(i, s[i]) (NULL if allocation fails) */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* Allocate and return a tab of substring of s
** , cuting s along c (NULL if allocation fails) */
char	**ft_split(char const *s, char c);

/* Return 1 if there is tofind in src, 0 other wise*/
int		ft_strcontain(char **src, char *tofind);

/* Create a new 0 terminated string of char */
char	*ft_strgen(char c, int n);

#endif
