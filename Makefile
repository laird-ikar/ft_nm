# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ***REMOVED*** <***REMOVED***@***REMOVED***>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 15:05:38 by ***REMOVED***            #+#    #+#              #
#    Updated: 2024/01/31 17:13:39 by ***REMOVED***           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	ft_nm

SRCS_DIR		=	srcs/
INCS_DIR		=	incs/
LIBS_DIR		=
LIBS_INCS_DIR	=	libft/

SOURCES			=	ft_nm init print_messages parse_file read_int get_data
INCLUDES		=	status t_nm t_target
LIBRARIES		=	libft

LIBS			=	$(foreach lib, $(LIBRARIES), $(LIBS_DIR)$(lib)/$(lib).a)
SRCS			=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SOURCES)))
INCS			=	$(addprefix $(INCS_DIR), $(addsuffix .h, $(SOURCES) $(INCLUDES)))
OBJS			=	$(SRCS:.c=.o)

SILENCER		=

CC				=	$(SILENCER)cc
CFLAGS			=	-Wall -Werror -Wextra $(addprefix -I, $(INCS_DIR) $(addprefix $(LIBS_DIR), $(LIBS_INCS_DIR)))
DEBUG_FLAGS		=	-g3

RM				= $(SILENCER)rm -rf

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

libs/libft/libft.a:
	$(MAKE) -C libs/libft

%.o:			%.c
	$(CC) $(CFLAGS) $^ -c -o $@

.PHONY: all clean fclean re debug
