/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:28:33 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/25 13:35:14 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	valid_map_char(t_map *map, int start);
static int	check_textures_and_colors(t_map *map);

void	check_valid_map(t_map *map)
{
	int	map_start;

	map_start = check_textures_and_colors(map);
	valid_map_char(map, map_start);
	valid_map_walls(map, map_start);
}

int	check_textures_and_colors(t_map *map)
{
	int	i;
	int	flags;

	i = 0;
	flags = 0;
	while (map->lines[i])
	{
		if (ft_strncmp(map->lines[i], "NO", 2) == 0 && flags == 0)
			flags += 32;
		else if (ft_strncmp(map->lines[i], "SO", 2) == 0 && flags == 32)
			flags += 16;
		else if (ft_strncmp(map->lines[i], "WE", 2) == 0 && flags == 48)
			flags += 8;
		else if (ft_strncmp(map->lines[i], "EA", 2) == 0 && flags == 56)
			flags += 4;
		else if (ft_strncmp(map->lines[i], "F", 1) == 0 && flags == 60)
			flags += 2;
		else if (ft_strncmp(map->lines[i], "C", 1) == 0 && flags == 62)
			flags += 1;
		i++;
	}
	if (flags != 63)
		destroy_map(map, "Not enough element in the map");
	return (i);
}

void	valid_map_char(t_map *map, int i)
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
