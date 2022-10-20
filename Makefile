NAME = fdf
CC = cc
CFLAGS = -c -Wall -Wextra -fsanitize=address -g -ggdb3# -Werror#TODO add flags
MLX = -lmlx -L ./mlx -framework AppKit -framework OpenGL
# MLX = -I/usr/include -Imlx_linux -O3
# MLX_LINUX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
# MLX = -lmlx -L mlx -framework AppKit -framework OpenGL
LIBFT = -lft -L libft
FT_PRINTF = -lftprintf -L ft_printf
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

%.c:
	@$(CC) $(CFLAGS) $(SRCS)

all: lib ftprintf $(NAME)

$(NAME): $(OBJS)
	@$(CC) -fsanitize=address -g -ggdb3 $(OBJS) $(MLX) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "fdf created😊🥑"

ftprintf:
	cd ft_printf && make

lib:
	cd libft && make 

clean:
	@rm -f ./*.o 

fclean: clean
	@rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re lib ftprintf