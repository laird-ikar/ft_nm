/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:45:41 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/05 08:56:15 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <stdlib.h>

/* Fill n byte of memory, at the address of s with 0s */
void	ft_bzero(void *s, size_t n);

/* Fill n byte of memory at the b address with the value of c */
void	*ft_memset(void *b, int c, size_t len);

/* Copy n byte of memory from src to dst */
void	*ft_memcpy(void *dst, void *src, size_t n);

/* Copy n byte of memory from src to dst in a
** non destructive way (safer if overlap) */
void	*ft_memmove(void *dst, const void *src, size_t len);

/* Return the address of the first occurence of
** c in the n bytes of memory pointed by s */
void	*ft_memchr(const void *s, int c, size_t n);

/* Allocate size byte of memeory and set them to 0
** (return NULL if allocation fails) */
void	*ft_calloc(size_t count, size_t size);

/* Allocate and return the contatenation of mem1 and mem2
** (return NULL if allocation fails)*/
void	*ft_memcat(
			const void *mem1,
			const void *mem2,
			size_t len1,
			size_t len2
			);

/* Compare the at most n first bytes of s1 and s2 and return
** the first diffrence */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
 *	Create and allocate a new spot of memory with the same data
 */
void	*ft_memdup(void *src, size_t len);

#endif
