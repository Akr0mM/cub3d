NAME    = cub3D
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -std=gnu99

MLX_DIR   = minilibx-linux
MLX_INC   = -Iinclude -I$(MLX_DIR)
MLX_LIB   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

SRCS    = srcs/main.c \
		  srcs/map/parser.c \
		  srcs/map/utils.c \
		  srcs/map/valid_map.c \
		  srcs/map/valid_walls.c \
		  srcs/map/textures.c \
		  srcs/mlx/init.c \
		  srcs/update/update.c \
		  srcs/update/collision.c \
		  srcs/render/render.c \
		  srcs/render/pixels.c \
		  srcs/render/ray.c \
		  srcs/render/textures.c
OBJS    = $(SRCS:%.c=build/%.o)

INC     = $(MLX_INC) $(LIBFT_INC)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(MAKE) -C $(MLX_DIR) CC="$(CC) -std=gnu99"
	$(CC) $(CFLAGS) $(OBJS) $(INC) $(MLX_LIB) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf build
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
