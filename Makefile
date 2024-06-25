# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyyyyyyy <yyyyyyyy@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 15:05:38 by yyyyyyyy          #+#    #+#              #
#    Updated: 2024/06/25 10:38:05 by yyyyyyyy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	ft_nm

SRCS_DIR		=	srcs/
INCS_DIR		=	incs/
LIBS_DIR		=
LIBS_INCS_DIR	=	libft/

SOURCES			=	analyze_file		ft_error	init		print_help		\
					array_2d			ft_nm		quick_sort					\
					parse_input	analyze_file_32bits	analyze_file_64bits
INCLUDES		=	struct	enum
LIBRARIES		=	libft

LIBS			=	$(foreach lib, $(LIBRARIES), $(LIBS_DIR)$(lib)/$(lib).a)
SRCS			=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SOURCES)))
INCS			=	$(addprefix $(INCS_DIR), $(addsuffix .h, $(SOURCES) $(INCLUDES)))
OBJS			=	$(SRCS:.c=.o)

SILENCER		=	@

CC				=	$(SILENCER)/bin/cc
CFLAGS			=	-Wall -Werror -Wextra $(addprefix -I, $(INCS_DIR) $(addprefix $(LIBS_DIR), $(LIBS_INCS_DIR)))
DEBUG_FLAGS		=	-g3 -D FT_DEBUG_MODE -fsanitize=address

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
