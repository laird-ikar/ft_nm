/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:00:22 by bguyot            #+#    #+#             */
/*   Updated: 2023/04/28 10:31:28 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stddef.h>
# include <stdlib.h>
# include "ft_memory.h"

# ifndef T_LIST
#  define T_LIST

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# endif

/* Return the number of element of the list lst*/
int		ft_lstsize(t_list *lst);

/* Return the maximum value of lst, interpreted as int */
int		ft_lstmaxint(t_list *lst);

/* Return the minimum value of lst, interpreted as int */
int		ft_lstminint(t_list *lst);

/* Add the new_lst list at the begining of the list pointed by lst */
void	ft_lstadd_front(t_list **lst, t_list *new_lst);

/* Add the new_lst list at the end of the list pointed by lst */
void	ft_lstadd_back(t_list **lst, t_list *new_lst);

/* Free the memory of the cont of lst with del THEN free
** DO NOT free the nx element */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/* Free the memory of the cont of lst with del THEN free
** DO free the nx element and set the original pointer to NULL */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/* Apply f to every element of lst */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/* Create and return a new_lst list with first element cont, and a NULL nx
** (NULL if allocation fails) */
t_list	*ft_lstnew(void *cont);

/* Return the lat element of a list */
t_list	*ft_lstlast(t_list *lst);

/* Return the calendarth element of lst */
t_list	*ft_lstnnext(t_list *lst, size_t n);

/* Return the list of the images of lst by f (NULL if allocation fails) */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
