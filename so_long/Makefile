NAME	=	so_long

BONUS	=	so_long_bonus

DIR_SRCS		=	srcs

DIR_SRCS_B		=	bonus

DIR_OBJS		=	objs

SRCS_NAMES		=	main.c parsing.c moves.c game.c movements.c steps.c

SRCS_NAMES_B	=	main_bonus.c parsing_bonus.c moves_bonus.c game_bonus.c movements_bonus.c steps_bonus.c

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

OBJS_NAMES_B	=	${SRCS_NAMES_B:.c=.o}

DEPS			=	${SRCS_NAMES:.c=.d}

DEPS_B			=	${SRCS_NAMES_B:.c=.d}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

SRCS_B			=	$(addprefix $(DIR_SRCS_B)/,$(SRCS_NAMES_B))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

OBJS_B			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES_B))

INC				=	-Iincludes

LIB				=	-Llibft -lft -Lft_printf -lftprintf

LIBFT			=	libft.a

PRINTF			=	libftprintf.a

CC				=	cc

CDFLAGS 		=	-MMD -MP

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

CFLAGS			=	-g3 -Wall -Werror -Wextra

all:	${NAME}

bonus:	${BONUS}

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

$(OBJS) : $(DIR_OBJS)/%.o : $(DIR_SRCS)/%.c
	$(CC) -g3 $(CDFLAGS) $(INC) -c $< -o $@ 

$(OBJS_B) : $(DIR_OBJS)/%.o : $(DIR_SRCS_B)/%.c
	$(CC) -g3 $(CDFLAGS) $(INC) -c $< -o $@ 

$(NAME): $(DIR_OBJS) $(OBJS) 
	make -C libft
	make -C ft_printf
	make -C mlx
	$(CC) -g3 ${INC} $(OBJS) $(LIB)  mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 -o $(NAME)
	@echo "\033[31;5mso_long\033[0m"

$(BONUS): $(DIR_OBJS) $(OBJS_B) 
	make -C libft
	make -C ft_printf
	make -C mlx
	$(CC) -g3 ${INC} $(OBJS_B) $(LIB)  mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 -o $(BONUS)
	@echo "\033[35;5mso_long_bonus\033[0m"

clean:
	make clean -C mlx
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
