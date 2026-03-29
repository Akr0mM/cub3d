/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:21:27 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/29 00:04:54 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "cub3d.h"

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

void	parse_and_validate(t_game *g, int ac, char **av);
void	destroy_map(t_map *map, char *err);
void	check_valid_map(t_map *map);
int		is_dir(char c);
int		valid_map_name(char *name);
void	create_rect_map(char ***rect_map, t_map *map, int start);
void	valid_map_walls(t_map *map, int i);
void	get_texture(t_map *map, char *line, char *dir);
void	load_textures(t_game *g);
void	alloc_map(t_map *map);
void	get_color(t_map *map, char *line, char *dir);
void	init_cam_dir(t_game *g, char dir);

#endif