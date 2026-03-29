/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 21:29:01 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/29 05:09:42 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	draw_ceiling_floor(t_game *g);
static void	draw_walls(t_game *g);
static void	draw_vertical_line(t_game *g, t_ray ray);

void	render_frame(t_game *g)
{
	draw_ceiling_floor(g);
	draw_walls(g);
	mlx_put_image_to_window(g->mlx, g->win, g->frame_buffer.img, 0, 0);
}

static void	draw_walls(t_game *g)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(g, &ray, x);
		init_dist(g, &ray);
		dda(g, &ray);
		draw_vertical_line(g, ray);
		x++;
	}
}

static void	draw_ceiling_floor(t_game *g)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y <= WIN_HEIGHT / 2)
			color = g->map.ceilling_color;
		else
			color = g->map.floor_color;
		x = 0;
		while (x < WIN_WIDTH)
		{
			put_pixel(&g->frame_buffer, x, y, color);
			x++;
		}
		y++;
	}
}

static void	draw_vertical_line(t_game *g, t_ray ray)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = (int)(WIN_HEIGHT / ray.perp_dist);
	draw_start = WIN_HEIGHT / 2 - line_height / 2;
	draw_end = WIN_HEIGHT / 2 + line_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	if (ray.side == 1 && ray.ray.y > 0)
		draw_vertical_line_north(g, ray, draw_start, draw_end);
	else if (ray.side == 1 && ray.ray.y < 0)
		draw_vertical_line_south(g, ray, draw_start, draw_end);
	else if (ray.side == 0 && ray.ray.x > 0)
		draw_vertical_line_west(g, ray, draw_start, draw_end);
	else if (ray.side == 0 && ray.ray.x < 0)
		draw_vertical_line_east(g, ray, draw_start, draw_end);
}
