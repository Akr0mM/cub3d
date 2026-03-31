/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:21:12 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/31 22:38:45 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	init_lines(t_map *map, char *map_file);
static void	get_each_lines(t_map *map, char *map_file);
static void	parse_textures(t_map *map);
static void	parse_map(t_game *g);

void	parse_and_validate(t_game *g, int ac, char **av)
{
	if (ac != 2)
		print_error("Not a valid number of arguments");
	valid_map_name(av[1]);
	get_each_lines(&g->map, av[1]);
	check_valid_map(&g->map);
	parse_textures(&g->map);
	parse_map(g);
}

static void	parse_map(t_game *g)
{
	int	i;
	int	j;

	alloc_map(&g->map);
	i = 0;
	while (i < g->map.size)
	{
		j = 0;
		while (g->map.lines[i + g->map.start][j]
			&& g->map.lines[i + g->map.start][j] != '\n')
		{
			if (is_dir(g->map.lines[i + g->map.start][j]))
			{
				g->map.grid[i][j] = 1;
				g->cam.pos.x = (double)j + 0.50;
				g->cam.pos.y = (double)i + 0.50;
				init_cam_dir(g, g->map.lines[i + g->map.start][j]);
			}
			else if (g->map.lines[i + g->map.start][j] != ' ')
				g->map.grid[i][j] = g->map.lines[i + g->map.start][j] - '0' + 1;
			j++;
		}
		g->map.grid[i][j] = -1;
		i++;
	}
}

static void	parse_textures(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->lines[i])
	{
		j = 0;
		while (map->lines[i][j] == ' ')
			j++;
		if (ft_strncmp(map->lines[i] + j, "NO", 2) == 0)
			get_texture(map, map->lines[i] + j, "NO");
		else if (ft_strncmp(map->lines[i] + j, "SO", 2) == 0)
			get_texture(map, map->lines[i] + j, "SO");
		else if (ft_strncmp(map->lines[i] + j, "WE", 2) == 0)
			get_texture(map, map->lines[i] + j, "WE");
		else if (ft_strncmp(map->lines[i] + j, "EA", 2) == 0)
			get_texture(map, map->lines[i] + j, "EA");
		else if (ft_strncmp(map->lines[i] + j, "F", 1) == 0)
			get_color(map, map->lines[i] + j, "F");
		else if (ft_strncmp(map->lines[i] + j, "C", 1) == 0)
			get_color(map, map->lines[i] + j, "C");
		i++;
	}
}

static void	get_each_lines(t_map *map, char *map_file)
{
	int		fd;
	int		i;
	char	*line;

	init_lines(map, map_file);
	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		print_perror("map: open");
	line = get_next_line(fd);
	while (line)
	{
		map->lines[i++] = line;
		line = get_next_line(fd);
	}
	close(fd);
}

static void	init_lines(t_map *map, char *map_file)
{
	int		nb;
	int		fd;
	char	*line;

	nb = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		print_perror("map: open");
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
		print_error("Malloc error");
	map->lines[nb] = NULL;
}
