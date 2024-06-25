NAME		=	ft_nm

SRCS_DIR	=	srcs/
INCS_DIR	=	incs/ libft/
LIBS_DIR	=

SOURCES		=	ft_nm init print_messages parse_file read_int get_data
LIBRARIES	=	libft

LIBS		= $(foreach lib, $(LIBRARIES), $(LIBS_DIR)$(lib)/$(lib).a)
SRCS		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SOURCES)))
OBJS		= $(SRCS:.c=.o)

SILENCER	=

CC			=	$(SILENCER)cc
CFLAGS		=	-Wall -Werror -Wextra $(addprefix -I, $(INCS_DIR))
DEBUG_FLAGS	=	-g3 # -fsanitize=address

RM			= $(SILENCER)rm -rf

all:		$(NAME)

clean:
	$(foreach path, $(LIBRARIES), $(MAKE) -C $(LIBS_DIR)$(path) clean ;)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: 		fclean all

$(NAME):	$(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@

debug:		CFLAGS+=$(DEBUG_FLAGS)
debug:		$(NAME)

libs/libft/libft.a:
	$(MAKE) -C libs/libft

%.o:		%.c
	$(CC) $(CFLAGS) $^ -c -o $@

.PHONY: all clean fclean re debug
