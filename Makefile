NAME    = cub3d
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

MLX_DIR   = minilibx-linux
MLX_INC   = -Iinclude -I$(MLX_DIR)
MLX_LIB   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

SRCS    = src/main.c \
		  src/map/parser.c \
		  src/map/utils.c \
		  src/map/valid_map.c \
		  src/map/valid_walls.c \
		  src/map/textures.c \
		  src/mlx/init.c \
		  src/update/update.c \
		  src/update/collision.c \
		  src/render/render.c \
		  src/render/pixels.c \
		  src/render/ray.c
OBJS    = $(SRCS:%.c=build/%.o)

INC     = $(MLX_INC) $(LIBFT_INC)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(MAKE) -C $(MLX_DIR)
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
