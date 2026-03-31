/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:21:24 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/31 22:38:36 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	init_cam_plane(t_game *g, char dir);

void	destroy_map(t_map *map, char *err)
{
	int	i;

	i = 0;
	while (map->lines && map->lines[i])
	{
		free(map->lines[i]);
		i++;
	}
	i = 0;
	while (map->grid && map->grid[i])
	{
		free(map->grid[i]);
		i++;
	}
	free(map->lines);
	free(map->grid);
	free(map->textures.no_path);
	free(map->textures.so_path);
	free(map->textures.we_path);
	free(map->textures.ea_path);
	if (err)
		print_error(err);
}

int	is_dir(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	valid_map_name(char *name)
{
	int	i;

	i = 0;
	while (name[i])
		i++;
	if (name[i - 1] != 'b' || name[i - 2] != 'u'
		|| name[i - 3] != 'c' || name[i - 4] != '.')
		print_error("Not a valid map extension");
}

void	init_cam_dir(t_game *g, char dir)
{
	if (dir == 'N')
	{
		g->cam.dir.x = 0.00;
		g->cam.dir.y = -1.00;
	}
	else if (dir == 'S')
	{
		g->cam.dir.x = 0.00;
		g->cam.dir.y = 1.00;
	}
	else if (dir == 'W')
	{
		g->cam.dir.x = -1.00;
		g->cam.dir.y = 0.00;
	}
	else if (dir == 'E')
	{
		g->cam.dir.x = 1.00;
		g->cam.dir.y = 0.00;
	}
	g->cam.speed = 0.014;
	g->cam.rot_speed = 0.0105;
	init_cam_plane(g, dir);
}

static void	init_cam_plane(t_game *g, char dir)
{
	if (dir == 'N')
	{
		g->cam.plane.x = 0.66;
		g->cam.plane.y = 0.00;
	}
	else if (dir == 'S')
	{
		g->cam.plane.x = -0.66;
		g->cam.plane.y = 0.00;
	}
	else if (dir == 'W')
	{
		g->cam.plane.x = 0.00;
		g->cam.plane.y = -0.66;
	}
	else if (dir == 'E')
	{
		g->cam.plane.x = 0.00;
		g->cam.plane.y = 0.66;
	}
}
