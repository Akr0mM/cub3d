/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 21:27:05 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/29 03:51:00 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"

static void	update_movement(t_game *g, double speed);
static void	update_right_rotation(t_game *g);
static void	update_left_rotation(t_game *g);

void	update_game(t_game *g)
{
	double	speed;

	if ((g->keys.w || g->keys.s) && (g->keys.a || g->keys.d))
		speed = g->cam.speed / sqrt(2.0);
	else
		speed = g->cam.speed;
	update_movement(g, speed);
	update_left_rotation(g);
	update_right_rotation(g);
}

static void	update_right_rotation(t_game *g)
{
	double	old_dir_x;
	double	old_plane_x;

	if (g->keys.r)
	{
		old_dir_x = g->cam.dir.x;
		g->cam.dir.x = g->cam.dir.x * cos(g->cam.rot_speed)
			- g->cam.dir.y * sin(g->cam.rot_speed);
		g->cam.dir.y = old_dir_x * sin(g->cam.rot_speed)
			+ g->cam.dir.y * cos(g->cam.rot_speed);
		old_plane_x = g->cam.plane.x;
		g->cam.plane.x = g->cam.plane.x * cos(g->cam.rot_speed)
			- g->cam.plane.y * sin(g->cam.rot_speed);
		g->cam.plane.y = old_plane_x * sin(g->cam.rot_speed)
			+ g->cam.plane.y * cos(g->cam.rot_speed);
	}
}

static void	update_left_rotation(t_game *g)
{
	double	old_dir_x;
	double	old_plane_x;

	if (g->keys.l)
	{
		old_dir_x = g->cam.dir.x;
		g->cam.dir.x = g->cam.dir.x * cos(-g->cam.rot_speed)
			- g->cam.dir.y * sin(-g->cam.rot_speed);
		g->cam.dir.y = old_dir_x * sin(-g->cam.rot_speed)
			+ g->cam.dir.y * cos(-g->cam.rot_speed);
		old_plane_x = g->cam.plane.x;
		g->cam.plane.x = g->cam.plane.x * cos(-g->cam.rot_speed)
			- g->cam.plane.y * sin(-g->cam.rot_speed);
		g->cam.plane.y = old_plane_x * sin(-g->cam.rot_speed)
			+ g->cam.plane.y * cos(-g->cam.rot_speed);
	}
}

static void	update_movement(t_game *g, double speed)
{
	t_vec2	new_pos;

	new_pos.x = g->cam.pos.x;
	new_pos.y = g->cam.pos.y;
	if (g->keys.w)
	{
		new_pos.x += g->cam.dir.x * speed;
		new_pos.y += g->cam.dir.y * speed;
	}
	if (g->keys.a)
	{
		new_pos.x += g->cam.dir.y * speed;
		new_pos.y += -g->cam.dir.x * speed;
	}
	if (g->keys.d)
	{
		new_pos.x += -g->cam.dir.y * speed;
		new_pos.y += g->cam.dir.x * speed;
	}
	if (g->keys.s)
	{
		new_pos.x += -g->cam.dir.x * speed;
		new_pos.y += -g->cam.dir.y * speed;
	}
	check_correct_pos(g, new_pos);
}
