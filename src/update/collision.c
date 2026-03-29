/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 03:44:34 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/29 03:45:01 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"

int	is_wall(t_game *g, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)floor(x);
	map_y = (int)floor(y);
	return (g->map.grid[map_y][map_x] == 2);
}

int	can_move_to(t_game *g, double x, double y)
{
	return (!is_wall(g, x - PLAYER_RADIUS, y)
		&& !is_wall(g, x + PLAYER_RADIUS, y)
		&& !is_wall(g, x, y - PLAYER_RADIUS)
		&& !is_wall(g, x, y + PLAYER_RADIUS));
}

void	check_correct_pos(t_game *g, t_vec2 new_pos)
{
	if (can_move_to(g, new_pos.x, g->cam.pos.y))
		g->cam.pos.x = new_pos.x;
	if (can_move_to(g, g->cam.pos.x, new_pos.y))
		g->cam.pos.y = new_pos.y;
}
