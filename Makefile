NAME 		= fdf
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror#-fsanitize=address -g -ggdb3  #-Werror#TODO add flags
MLX 		= -lmlx -L ./mlx -framework AppKit -framework OpenGL
LIBFT 		= -lft -L libft
FT_PRINTF 	= -lftprintf -L ft_printf
SRCS		= $(shell find "." -maxdepth 1 -name '*.c' ! -name "*_bonus.c")
BONUS_SRCS 	= $(shell find "." -maxdepth 1 -name '*.c' ! -name "main.c")
OBJS 		= $(SRCS:%.c=%.o)
BONUS_OBJS	= $(BONUS_SRCS:%.c=%.o)

%.c:
	@$(CC) $(CFLAGS) $(BONUS_SRCS)

all: lib ftprintf $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLX) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo -e "$(GREEN)✅$(NAME) created!$(DEFAULT) 😊🥑"

ftprintf:
	@cd ft_printf && make

lib:
	@cd libft && make

clean:
	@rm -f ./*.o
	@echo -e "$(YELLOW)🧨 Object files deleted!$(DEFAULT)"

fclean: clean
	@cd ./libft && make fclean
	@cd ./ft_printf && make fclean
	@rm -f $(NAME)
	@echo -e "$(RED)💣 All deleted!$(DEFAULT)"

bonus: $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(MLX) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo -e "$(GREEN)✅$(NAME)_bonus created!$(DEFAULT) 😊🥑"

re: fclean all

.PHONY: all clean fclean re lib ftprintf

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m

