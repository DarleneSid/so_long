NAME	=	so_long

DIR_SRCS		=	srcs

DIR_OBJS		=	objs

SRCS_NAMES		=	main.c

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

DEPS			=	${SRCS_NAMES:.c=.d}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

INC				=	-Iincludes

LIB				=	-Llibft -lft -Lft_printf -lftprintf

LIBFT			=	libft.a

PRINTF			=	libftprintf.a

CC				=	cc

CDFLAGS 		=	-MMD -MP

CFLAGS			=	-g3 -Wall -Werror -Wextra

all:	${NAME}

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

$(OBJS) : $(DIR_OBJS)/%.o : $(DIR_SRCS)/%.c
	$(CC) -g3 $(CDFLAGS) $(INC) -c $< -o $@ 

$(NAME): $(DIR_OBJS) $(OBJS) 
	make -C libft
	make -C ft_printf
	$(CC) -g3 ${INC} $(OBJS) $(LIB) -o $(NAME)
	@echo "\033[31;5mso_long\033[0m"

clean:
	make clean -C libft
	make clean -C ft_printf
	rm -rf ${DIR_OBJS}

fclean:	clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -rf ${LIBFT}
	rm -rf ${NAME}

re:	fclean all

-include $(DEPS)

.PHONY:	all clean fclean re