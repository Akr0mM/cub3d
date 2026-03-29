/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 05:04:27 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/29 05:23:42 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_vertical_line_north(t_game *g, t_ray ray,
		int draw_start, int draw_end)
{
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;

	wall_x = ray.ray.x - (int)ray.ray.x;
	step = g->map.textures.no.height / (draw_end - draw_start);
	tex_pos = (draw_start - WIN_HEIGHT / 2
			+ (draw_end - draw_start) / 2) * step;
	tex_x = wall_x * g->map.textures.no.width;
	while (draw_start <= draw_end)
	{
		tex_y = (int)tex_pos;
		put_pixel(&g->frame_buffer, ray.ray.x, draw_start, get_color_from_texture(g->map.textures.no, tex_x, tex_y));
		draw_start++;
	}
}

void	draw_vertical_line_south(t_game *g, t_ray ray,
		int draw_start, int draw_end)
{
	double	wall_x;

	wall_x = ray.ray.x - (int)ray.ray.x;
}

void	draw_vertical_line_west(t_game *g, t_ray ray,
		int draw_start, int draw_end)
{
	double	wall_x;

	wall_x = ray.ray.y - (int)ray.ray.y;
}

void	draw_vertical_line_east(t_game *g, t_ray ray,
		int draw_start, int draw_end)
{
	double	wall_x;

	wall_x = ray.ray.y - (int)ray.ray.y;
}
