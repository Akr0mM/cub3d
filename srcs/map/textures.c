/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:54:06 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/31 22:33:41 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	get_texture(t_map *map, char *line, char *dir)
{
	int		len;
	char	*end;
	char	*path;

	while (*line == ' ')
		line++;
	len = 0;
	while (line[len] && line[len] != ' ' && line[len] != '\n')
		len++;
	end = line + len;
	while (*end == ' ')
		end++;
	if (!len || (*end && *end != '\n'))
		destroy_map(map, "Invalid texture path");
	path = ft_strndup(line, len);
	if (!path)
		destroy_map(map, "Malloc error");
	if (ft_strcmp(dir, "NO") == 0)
		map->textures.no_path = path;
	else if (ft_strcmp(dir, "SO") == 0)
		map->textures.so_path = path;
	else if (ft_strcmp(dir, "WE") == 0)
		map->textures.we_path = path;
	else
		map->textures.ea_path = path;
}

static int	get_color_value(t_map *map, char **line, char separator)
{
	int	value;

	while (**line == ' ')
		(*line)++;
	if (!ft_isdigit(**line))
		destroy_map(map, "Invalid color");
	value = 0;
	while (ft_isdigit(**line))
	{
		value = value * 10 + **line - '0';
		if (value > 255)
			destroy_map(map, "Invalid color");
		(*line)++;
	}
	while (**line == ' ')
		(*line)++;
	if (**line == separator)
		(*line)++;
	else if (**line || separator == ',')
		destroy_map(map, "Invalid color");
	return (value);
}

void	get_color(t_map *map, char *line, char *dir)
{
	int	r;
	int	g;
	int	b;

	line += 1;
	r = get_color_value(map, &line, ',');
	g = get_color_value(map, &line, ',');
	b = get_color_value(map, &line, '\n');
	if (ft_strcmp(dir, "F") == 0)
		map->floor_color = (r << 16) | (g << 8) | b;
	else
		map->ceilling_color = (r << 16) | (g << 8) | b;
}

void	load_textures(t_game *g)
{
	t_textures	*t;

	t = &g->map.textures;
	t->no.img = mlx_xpm_file_to_image(g->mlx, t->no_path,
			&t->no.width, &t->no.height);
	t->so.img = mlx_xpm_file_to_image(g->mlx, t->so_path,
			&t->so.width, &t->so.height);
	t->we.img = mlx_xpm_file_to_image(g->mlx, t->we_path,
			&t->we.width, &t->we.height);
	t->ea.img = mlx_xpm_file_to_image(g->mlx, t->ea_path,
			&t->ea.width, &t->ea.height);
	if (!t->no.img || !t->so.img || !t->we.img || !t->ea.img)
		destroy_all(g, "Could not load wall texture");
	t->no.addr = mlx_get_data_addr(t->no.img,
			&t->no.bpp, &t->no.line_len, &t->no.endian);
	t->so.addr = mlx_get_data_addr(t->so.img,
			&t->so.bpp, &t->so.line_len, &t->so.endian);
	t->we.addr = mlx_get_data_addr(t->we.img,
			&t->we.bpp, &t->we.line_len, &t->we.endian);
	t->ea.addr = mlx_get_data_addr(t->ea.img,
			&t->ea.bpp, &t->ea.line_len, &t->ea.endian);
}

void	alloc_map(t_map *map)
{
	int	i;

	map->grid = ft_calloc(map->size + 1, sizeof(int *));
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
}
