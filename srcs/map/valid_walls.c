/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:30:46 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/29 01:30:51 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	free_rect_map(char ***rect_map);
static void	fill_rect_map(char ***rect_map, t_map *map, int max, int start);
static char	*empty_line(t_map *map, int w, char ***rect_map);

void	valid_map_walls(t_map *map, int i)
{
	int		j;
	char	**rect_map;

	create_rect_map(&rect_map, map, i);
	while (map->lines[i])
	{
		j = 0;
		while (map->lines[i][j] && map->lines[i][j] != '\n')
		{
			if ((map->lines[i][j] == '0' || is_dir(map->lines[i][j]))
				&& (rect_map[i - 1][j + 1] == ' '
					|| rect_map[i + 1][j + 1] == ' ' || rect_map[i][j] == ' '
						|| rect_map[i][j + 2] == ' '))
			{
				free_rect_map(&rect_map);
				destroy_map(map, "Map is not closed by walls");
			}
			j++;
		}
		i++;
	}
	free_rect_map(&rect_map);
}

void	create_rect_map(char ***rect_map, t_map *map, int start)
{
	int	i;
	int	j;
	int	max;

	i = start;
	while (map->lines[i])
		i++;
	map->size = i - start;
	*rect_map = ft_calloc(i + 2, sizeof(char *));
	if (!*rect_map)
		destroy_map(map, "Error malloc");
	i = start;
	max = 0;
	while (map->lines[i])
	{
		j = 0;
		while (map->lines[i][j] != '\n' && map->lines[i][j] != '\0')
			j++;
		if (j > max)
			max = j;
		i++;
	}
	map->line_len = max;
	fill_rect_map(rect_map, map, max, start);
}

static void	fill_rect_map(char ***rect_map, t_map *map, int max, int start)
{
	int	i;
	int	j;
	int	w;

	w = max + 2;
	i = 0;
	while (i < start)
		(*rect_map)[i++] = empty_line(map, w, rect_map);
	while (map->lines[i])
	{
		(*rect_map)[i] = empty_line(map, w, rect_map);
		j = -1;
		while (++j < max && map->lines[i][j] && map->lines[i][j] != '\n')
			(*rect_map)[i][j + 1] = map->lines[i][j];
		(*rect_map)[i++][w] = '\0';
	}
	(*rect_map)[i] = empty_line(map, w, rect_map);
}

static char	*empty_line(t_map *map, int w, char ***rect_map)
{
	char	*line;
	int		j;

	line = malloc(w + 1);
	if (!line)
	{
		free_rect_map(rect_map);
		destroy_map(map, "Malloc error");
	}
	j = -1;
	while (++j < w)
		line[j] = ' ';
	line[w] = '\0';
	return (line);
}

static void	free_rect_map(char ***rect_map)
{
	int	i;

	i = 0;
	while ((*rect_map)[i])
	{
		free((*rect_map)[i]);
		i++;
	}
	free(*rect_map);
}
