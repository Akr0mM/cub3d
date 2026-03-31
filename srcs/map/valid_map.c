/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:28:33 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/31 22:31:42 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	valid_map_char(t_map *map, int start);
static void	check_textures_and_colors(t_map *map, int map_start);
static int	find_map_start(t_map *map);
static int	check_colors(t_map *map, int map_start);

void	check_valid_map(t_map *map)
{
	int	map_start;

	map_start = find_map_start(map);
	check_textures_and_colors(map, map_start);
	valid_map_char(map, map_start);
	valid_map_walls(map, map_start);
	map->start = map_start;
}

static void	check_textures_and_colors(t_map *map, int map_start)
{
	int	i;
	int	flags;
	int	j;

	i = 0;
	flags = 0;
	while (map->lines[i] && i < map_start)
	{
		j = 0;
		while (map->lines[i][j] == ' ')
			j++;
		if (ft_strncmp(map->lines[i] + j, "NO", 2) == 0)
			flags += 32;
		else if (ft_strncmp(map->lines[i] + j, "SO", 2) == 0)
			flags += 16;
		else if (ft_strncmp(map->lines[i] + j, "WE", 2) == 0)
			flags += 8;
		else if (ft_strncmp(map->lines[i] + j, "EA", 2) == 0)
			flags += 4;
		i++;
	}
	flags += check_colors(map, map_start);
	if (flags != 63)
		destroy_map(map, "Not enough element in the map");
}

static int	check_colors(t_map *map, int map_start)
{
	int	i;
	int	flags;
	int	j;

	i = 0;
	flags = 0;
	while (map->lines[i] && i < map_start)
	{
		j = 0;
		while (map->lines[i][j] == ' ')
			j++;
		if (ft_strncmp(map->lines[i] + j, "F", 1) == 0)
		{
			flags += 2;
			check_color_line(map, map->lines[i], j + 1);
		}
		else if (ft_strncmp(map->lines[i] + j, "C", 1) == 0)
		{
			flags += 1;
			check_color_line(map, map->lines[i], j + 1);
		}
		i++;
	}
	return (flags);
}

static void	valid_map_char(t_map *map, int i)
{
	int	found_start;
	int	j;

	found_start = 0;
	while (map->lines[i])
	{
		j = 0;
		while (map->lines[i][j] != '\n' && map->lines[i][j] != '\0')
		{
			if (map->lines[i][j] != ' ' && map->lines[i][j] != '0'
					&& map->lines[i][j] != '1' && !is_dir(map->lines[i][j])
						&& !found_start)
				destroy_map(map, "Wrong character found in map");
			if (found_start && is_dir(map->lines[i][j]))
				destroy_map(map, "Starting position found twice");
			if (is_dir(map->lines[i][j]))
				found_start = 1;
			j++;
		}
		i++;
	}
	if (!found_start)
		destroy_map(map, "Starting position not found");
}

static int	find_map_start(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->lines[i])
	{
		j = 0;
		while (map->lines[i][j] == ' ')
			j++;
		if (map->lines[i][j] == '1' || map->lines[i][j] == '0')
			return (i);
		i++;
	}
	destroy_map(map, "No map found");
	return (i);
}
