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
static int	get_element_flag(char *line);

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
	int		i;
	int		flags;
	int		flag;
	char	*line;

	i = 0;
	flags = 0;
	while (i < map_start)
	{
		line = map->lines[i++];
		while (*line == ' ')
			line++;
		flag = get_element_flag(line);
		if (flag < 0)
			destroy_map(map, "Unknown or invalid scene element");
		if (flags & flag)
			destroy_map(map, "Duplicate scene element");
		flags |= flag;
	}
	if (flags != 63)
		destroy_map(map, "Missing texture or color");
}

static int	get_element_flag(char *line)
{
	if (!*line || *line == '\n')
		return (0);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (32);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (16);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (8);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (4);
	if (ft_strncmp(line, "F ", 2) == 0)
		return (2);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (-1);
}

static void	valid_map_char(t_map *map, int i)
{
	int	found_start;
	int	j;

	found_start = 0;
	while (map->lines[i])
	{
		if (map->lines[i][0] == '\n')
			destroy_map(map, "Empty line in the map");
		j = 0;
		while (map->lines[i][j] != '\n' && map->lines[i][j] != '\0')
		{
			if (map->lines[i][j] != ' ' && map->lines[i][j] != '0'
				&& map->lines[i][j] != '1' && !is_dir(map->lines[i][j]))
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
