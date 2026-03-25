/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:21:12 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/25 14:26:50 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	init_lines(t_map *map, char *map_file);
static void	parse_each_lines(t_map *map, char *map_file);

void	parse_and_validate(t_game *g, int ac, char **av)
{
	if (ac != 2)
		map_error("Not a valid number of arguments");
	if (!valid_map_name(av[1]))
		map_error("Not a valid map extension");
	parse_each_lines(&g->map, av[1]);
	check_valid_map(&g->map);
}

void	parse_each_lines(t_map *map, char *map_file)
{
	int		fd;
	int		i;
	char	*line;

	init_lines(map, map_file);
	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		map_perror("map: open");
	line = get_next_line(fd);
	while (line)
	{
		map->lines[i++] = line;
		line = get_next_line(fd);
	}
	close(fd);
}

void	init_lines(t_map *map, char *map_file)
{
	int		nb;
	int		fd;
	char	*line;

	nb = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		map_perror("map: open");
	line = get_next_line(fd);
	while (line)
	{
		nb++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->lines = malloc(sizeof(char *) * (nb + 1));
	if (!map->lines)
		map_error("Malloc error");
	map->lines[nb] = NULL;
}
