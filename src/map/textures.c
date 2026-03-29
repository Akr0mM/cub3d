/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:54:06 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/28 23:52:45 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	get_texture(t_map *map, char *line, char *dir)
{
	int	i;
	int	j;

	i = 0;
	line += 2;
	while (line[i] == ' ')
		i++;
	j = i;
	while (line[j] && line[j] != ' ' && line[j] != '\n')
		j++;
	if (ft_strcmp(dir, "NO") == 0)
		map->textures.no_path = ft_strndup(line + i, j - i);
	else if (ft_strcmp(dir, "SO") == 0)
		map->textures.so_path = ft_strndup(line + i, j - i);
	else if (ft_strcmp(dir, "WE") == 0)
		map->textures.we_path = ft_strndup(line + i, j - i);
	else if (ft_strcmp(dir, "EA") == 0)
		map->textures.ea_path = ft_strndup(line + i, j - i);
}

void	get_color(t_map *map, char *line, char *dir)
{
	int	i;
	int	r;
	int	g;
	int	b;

	line += 1;
	i = 0;
	while (line[i] == ' ')
		i++;
	r = ft_atoi(line + i);
	while (line[i - 1] != ',')
		i++;
	g = ft_atoi(line + i);
	i++;
	while (line[i - 1] != ',')
		i++;
	b = ft_atoi(line + i);
	if (ft_strcmp(dir, "F") == 0)
		map->floor_color = (r << 16) | (g << 8) | b;
	else
		map->ceilling_color = (r << 16) | (g << 8) | b;

	printf("%d %d %d\n", r, g, b);
}

void	load_textures(t_game *g)
{
	g->map.textures.no.img = mlx_xpm_file_to_image(g->mlx,
			g->map.textures.no_path, &g->map.textures.no.width,
			&g->map.textures.no.height);
	g->map.textures.so.img = mlx_xpm_file_to_image(g->mlx,
			g->map.textures.so_path, &g->map.textures.so.width,
			&g->map.textures.so.height);
	g->map.textures.we.img = mlx_xpm_file_to_image(g->mlx,
			g->map.textures.we_path, &g->map.textures.we.width,
			&g->map.textures.we.height);
	g->map.textures.ea.img = mlx_xpm_file_to_image(g->mlx,
			g->map.textures.ea_path, &g->map.textures.ea.width,
			&g->map.textures.ea.height);
	g->map.textures.no.addr = mlx_get_data_addr(g->map.textures.no.img,
			&g->map.textures.no.bpp, &g->map.textures.no.line_len,
			&g->map.textures.no.endian);
	g->map.textures.so.addr = mlx_get_data_addr(g->map.textures.so.img,
			&g->map.textures.so.bpp, &g->map.textures.so.line_len,
			&g->map.textures.so.endian);
	g->map.textures.we.addr = mlx_get_data_addr(g->map.textures.we.img,
			&g->map.textures.we.bpp, &g->map.textures.we.line_len,
			&g->map.textures.we.endian);
	g->map.textures.ea.addr = mlx_get_data_addr(g->map.textures.ea.img,
			&g->map.textures.ea.bpp, &g->map.textures.ea.line_len,
			&g->map.textures.ea.endian);
}

void	alloc_map(t_map *map)
{
	int	i;

	map->grid = malloc(sizeof(int *) * (map->size + 1));
	if (!map->grid)
		destroy_map(map, "Malloc error");
	i = 0;
	while (i < map->size)
	{
		map->grid[i] = (int *)ft_calloc(map->line_len + 1, sizeof(int));
		if (!map->grid[i])
			destroy_map(map, "Malloc error");
		i++;
	}
	map->grid[i] = NULL;
}