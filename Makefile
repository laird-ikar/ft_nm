NAME		=	ft_nm

SRCS_DIR	=	srcs/
INCS_DIR	=	incs/
LIBS_DIR	=

SOURCES		=
LIBRARIES	=	libft

LIBS		= $(foreach lib, $(LIBRARIES), $(LIBS_DIR)$(lib)/$(lib).a)
SRCS		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SOURCES)))
OBJS		= $(SRCS:.c=.o)

SILENCER	=

CC			=	$(SILENCER)cc
CFLAGS		=	-I $(LIBS_DIR)

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

libs/libft/libft.a:
	$(MAKE) -C libs/libft

%.o:		%.c
	$(CC) $(CFLAGS) $^ -c -o $@

.PHONY: all clean fclean re
