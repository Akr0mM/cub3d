/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:18:18 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/25 11:59:39 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"

typedef struct s_vec2
{
	int	x;
	int	y;
}	t_vec2;

typedef struct s_img
{
	char	*test;
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
	int			**grid;
	t_textures	textures;
	t_vec2		player_starting_pos;
}	t_map;

typedef struct s_game
{
	t_map	map;
}	t_game;

void	destroy_all(t_game *g);

#endif