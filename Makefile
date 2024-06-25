# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stage <***REMOVED***@***REMOVED***>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 15:05:38 by ***REMOVED***            #+#    #+#              #
#    Updated: 2024/06/05 10:58:36 by stage            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	ft_nm

SRCS_DIR		=	srcs/
INCS_DIR		=	incs/
LIBS_DIR		=
LIBS_INCS_DIR	=	libft/

SOURCES			=	analyze_file	ft_error	init		print_help			\
					array_2d		ft_nm		parse_input
INCLUDES		=	struct	enum
LIBRARIES		=	libft

LIBS			=	$(foreach lib, $(LIBRARIES), $(LIBS_DIR)$(lib)/$(lib).a)
SRCS			=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SOURCES)))
INCS			=	$(addprefix $(INCS_DIR), $(addsuffix .h, $(SOURCES) $(INCLUDES)))
OBJS			=	$(SRCS:.c=.o)

SILENCER		=	@

CC				=	$(SILENCER)/bin/cc
CFLAGS			=	-Wall -Werror -Wextra $(addprefix -I, $(INCS_DIR) $(addprefix $(LIBS_DIR), $(LIBS_INCS_DIR)))
DEBUG_FLAGS		=	-g -D FT_DEBUG_MODE -fsanitize=address

RM				= $(SILENCER)/bin/rm -rf

all:			$(NAME)

clean:
	$(foreach path, $(LIBRARIES), $(MAKE) -C $(LIBS_DIR)$(path) clean ;)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: 			fclean all

$(NAME):		$(INCS) $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

debug:			CFLAGS+=$(DEBUG_FLAGS)
debug:			re

libft/libft.a:
	$(MAKE) -C libft

%.o:			%.c
	$(CC) $(CFLAGS) $^ -c -o $@

.PHONY: all clean fclean re debug
