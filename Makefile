NAME		=	ft_nm

SRCS_DIR	=	srcs/
INCS_DIR	=	incs/
LIBS_DIR	=	libs/

SOURCES		=
HEADERS		=
LIBRARIES	=

LIBS		=
SRCS		=
OBJS		=

SILENCER	=

CC			=	$(SILENCER)cc
CFLAGS		=

RM			= $(SILENCER)rm -rf

all:		$(NAME)

clean:
	$(foreach path, $(LIBRARIES), make -C $(LIBS_DIR)$(path) clean ;)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(NAME):	$(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@

%.c:		%.o
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: all clean fclean re
