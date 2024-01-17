# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 13:24:40 by bguyot            #+#    #+#              #
#    Updated: 2023/04/28 10:56:25 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=		libft.a

FT_ARR_DIR		=		src/ft_arr/
FT_ARR_FIL		=		\
	ft_sort_int_tab		\
	ft_tabmax			\
	ft_tabmed			\
	ft_tabmin
FT_ARR_SRC		=		\
	$(addsuffix .c, $(addprefix $(FT_ARR_DIR), $(FT_ARR_FIL)))

FT_CAST_DIR		=		src/ft_cast/
FT_CAST_FIL		=		\
	ft_tolower			\
	ft_toupper			\
	ft_atoi				\
	ft_itoa				\
	ft_utoa				\
	ft_utoa_base		\
	ft_ultoa_base		\
	ft_atobuf
FT_CAST_SRC		=		\
	$(addsuffix .c, $(addprefix $(FT_CAST_DIR), $(FT_CAST_FIL)))

FT_CHECK_DIR	=		src/ft_check/
FT_CHECK_FIL	=		\
	ft_isalnum			\
	ft_isalpha			\
	ft_isascii			\
	ft_isdigit			\
	ft_isprint			\
	ft_isspace
FT_CHECK_SRC	=		\
	$(addsuffix .c, $(addprefix $(FT_CHECK_DIR), $(FT_CHECK_FIL)))

FT_LIST_DIR		=		src/ft_list/
FT_LIST_FIL		=		\
	ft_lstadd_back		\
	ft_lstadd_front		\
	ft_lstclear			\
	ft_lstdelone		\
	ft_lstiter			\
	ft_lstlast			\
	ft_lstmap			\
	ft_lstmax			\
	ft_lstmin			\
	ft_lstnew			\
	ft_lstnnext			\
	ft_lstsize
FT_LIST_SRC		=		\
	$(addsuffix .c, $(addprefix $(FT_LIST_DIR), $(FT_LIST_FIL)))

FT_MATH_DIR		=		src/ft_math/
FT_MATH_FIL		=		\
	ft_abs				\
	ft_max				\
	ft_min				\
	ft_sqrt				\
	ft_sign
FT_MATH_SRC		=		\
	$(addsuffix .c, $(addprefix $(FT_MATH_DIR), $(FT_MATH_FIL)))

FT_MEMORY_DIR	=		src/ft_memory/
FT_MEMORY_FIL	=		\
	ft_bzero			\
	ft_calloc			\
	ft_memcat			\
	ft_memchr			\
	ft_memcmp			\
	ft_memcpy			\
	ft_memmove			\
	ft_memset			\
	ft_memdup
FT_MEMORY_SRC	=		\
	$(addsuffix .c, $(addprefix $(FT_MEMORY_DIR), $(FT_MEMORY_FIL)))

FT_PUT_DIR		=		src/ft_put/
FT_PUT_FIL		=		\
	ft_putchar_fd		\
	ft_putendl_fd		\
	ft_putnbr_fd		\
	ft_putstr_fd		\
	ft_puttab_fd
FT_PUT_SRC		=		\
	$(addsuffix .c, $(addprefix $(FT_PUT_DIR), $(FT_PUT_FIL)))

FT_STRING_DIR	=		src/ft_string/
FT_STRING_FIL	=		\
	ft_split			\
	ft_strchr			\
	ft_strcmp			\
	ft_strcontain		\
	ft_strdup			\
	ft_striteri			\
	ft_strjoin			\
	ft_strlcat			\
	ft_strlcpy			\
	ft_strlen			\
	ft_strmapi			\
	ft_strncmp			\
	ft_strndup			\
	ft_strnstr			\
	ft_strrchr			\
	ft_strtrim			\
	ft_substr			\
	ft_tabjoin			\
	ft_strgen
FT_STRING_SRC	=		\
	$(addsuffix .c, $(addprefix $(FT_STRING_DIR), $(FT_STRING_FIL)))

FT_BUFF_DIR		=		src/ft_buff/
FT_BUFF_FIL		=		\
	ft_bufcat			\
	ft_bufclear			\
	ft_bufcpy
FT_BUFF_SRC	=			\
	$(addsuffix .c, $(addprefix $(FT_BUFF_DIR), $(FT_BUFF_FIL)))

FT_GNL_DIR	=			src/get_next_line/
FT_GNL_FIL	=			\
	get_next_line
FT_GNL_SRC	=			\
	$(addsuffix .c, $(addprefix $(FT_GNL_DIR), $(FT_GNL_FIL)))

FT_PRINTF_DIR	=	src/ft_printf/
FT_PRINTF_FIL	=		\
	ft_printf			\
	ft_parse			\
	ft_split_module		\
	ft_stringify		\
	checkers			\
	expend_arg			\
	parsers/c			\
	parsers/d			\
	parsers/great_x		\
	parsers/i			\
	parsers/p			\
	parsers/percent		\
	parsers/s			\
	parsers/u			\
	parsers/x			\
	parsers/f			\
	parsers/apply_width	\
	parsers/update_flag
FT_PRINTF_SRC	=		\
	$(addsuffix .c, $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_FIL)))

SRCS =					\
	$(FT_ARR_SRC)		\
	$(FT_CAST_SRC)		\
	$(FT_CHECK_SRC)		\
	$(FT_LIST_SRC)		\
	$(FT_MATH_SRC)		\
	$(FT_MEMORY_SRC)	\
	$(FT_PUT_SRC)		\
	$(FT_STRING_SRC)	\
	$(FT_GNL_SRC)		\
	$(FT_BUFF_SRC)		\
	$(FT_PRINTF_SRC)

OBJS 			=		$(SRCS:.c=.o)

CC				=		@gcc
RM				=		@rm -rf
CFLAGS			=		-Wall -Wextra -Werror

OBJ_COLOR		=		"\e[38;5;147m"
CLN_COLOR		=		"\e[38;5;124m"
BIN_COLOR		=		"\e[38;5;129m"
ERRASE_LINE		=		"\e[2K\r"

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf $(ERRASE_LINE)$(BIN_COLOR)"\t"$(NAME)"\t\t\t\t[ ✓ ]\n\e[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf $(ERRASE_LINE)$(OBJ_COLOR)"\t"$@"\e[0m"

clean:
	$(RM) $(OBJS)
	@printf $(CLN_COLOR)"\tclean "$(NAME)" objects\t\t[ ✓ ]\n\e[0m"

fclean: clean
	$(RM) $(NAME)
	@printf $(CLN_COLOR)"\tclean "$(NAME)" binary\t\t[ ✓ ]\n\e[0m"

re: fclean all

.PHONY:	all clean fclean re
