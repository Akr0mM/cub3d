/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:18:18 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/29 04:44:42 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>

# define WIN_WIDTH 1500
# define WIN_HEIGHT 900
# define WIN_TITLE "cub3D"
# define PLAYER_RADIUS 0.10

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_textures
{
	char	*no_path;
	char	*so_path;
	char	*ea_path;
	char	*we_path;
	t_img	no;
	t_img	so;
	t_img	ea;
	t_img	we;
}	t_textures;

typedef struct s_map
{
	char		**lines;
	int			start;
	int			line_len;
	int			size;
	int			**grid;
	t_textures	textures;
	int			ceilling_color;
	int			floor_color;
}	t_map;

typedef struct s_camera
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	plane;
	double	speed;
	double	rot_speed;
}	t_camera;

typedef struct s_ray
{
	double	camera_x;
	t_vec2	ray;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_dist;
}	t_ray;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	l;
	int	r;
}	t_keys;

typedef struct s_game
{
	t_map		map;
	void		*mlx;
	void		*win;
	t_img		frame_buffer;
	t_camera	cam;
	t_keys		keys;
}	t_game;

void	destroy_all(t_game *g, char *err);
void	print_error(char *err);
void	print_perror(char *err);
void	init_mlx(t_game *g);
void	destroy_mlx(t_game *g);
int		game_loop(t_game *g);

#endif