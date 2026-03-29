/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 05:04:27 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/30 01:16:56 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	get_color_from_texture(t_img tex, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= tex.width || y < 0 || y >= tex.height)
		return (0);
	dst = tex.addr + (y * tex.line_len) + (x * (tex.bpp / 8));
	return (*(unsigned int *)dst);
}

void	draw_vertical_line_north(t_game *g, t_ray ray,
		int draw_start, int draw_end)
{
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;

	wall_x = g->cam.pos.x + ray.perp_dist * ray.ray.x;
	wall_x -= (int)wall_x;
	step = g->map.textures.no.height / (WIN_HEIGHT / ray.perp_dist);
	tex_pos = (draw_start - WIN_HEIGHT / 2
			+ (WIN_HEIGHT / ray.perp_dist) / 2) * step;
	tex_x = wall_x * g->map.textures.no.width;
	tex_x = g->map.textures.no.width - tex_x - 1;
	while (draw_start <= draw_end)
	{
		tex_y = (int)tex_pos;
		put_pixel(&g->frame_buffer, ray.x, draw_start,
			get_color_from_texture(g->map.textures.no, tex_x, tex_y));
		tex_pos += step;
		draw_start++;
	}
}

void	draw_vertical_line_south(t_game *g, t_ray ray,
		int draw_start, int draw_end)
{
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;

	wall_x = g->cam.pos.x + ray.perp_dist * ray.ray.x;
	wall_x -= (int)wall_x;
	step = g->map.textures.so.height / (WIN_HEIGHT / ray.perp_dist);
	tex_pos = (draw_start - WIN_HEIGHT / 2
			+ (WIN_HEIGHT / ray.perp_dist) / 2) * step;
	tex_x = wall_x * g->map.textures.so.width;
	while (draw_start <= draw_end)
	{
		tex_y = (int)tex_pos;
		put_pixel(&g->frame_buffer, ray.x, draw_start,
			get_color_from_texture(g->map.textures.so, tex_x, tex_y));
		tex_pos += step;
		draw_start++;
	}
}

void	draw_vertical_line_west(t_game *g, t_ray ray,
		int draw_start, int draw_end)
{
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;

	wall_x = g->cam.pos.y + ray.perp_dist * ray.ray.y;
	wall_x -= (int)wall_x;
	step = g->map.textures.we.height / (WIN_HEIGHT / ray.perp_dist);
	tex_pos = (draw_start - WIN_HEIGHT / 2
			+ (WIN_HEIGHT / ray.perp_dist) / 2) * step;
	tex_x = wall_x * g->map.textures.we.width;
	while (draw_start <= draw_end)
	{
		tex_y = (int)tex_pos;
		put_pixel(&g->frame_buffer, ray.x, draw_start,
			get_color_from_texture(g->map.textures.we, tex_x, tex_y));
		tex_pos += step;
		draw_start++;
	}
}

void	draw_vertical_line_east(t_game *g, t_ray ray,
		int draw_start, int draw_end)
{
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;

	wall_x = g->cam.pos.y + ray.perp_dist * ray.ray.y;
	wall_x -= (int)wall_x;
	step = g->map.textures.ea.height / (WIN_HEIGHT / ray.perp_dist);
	tex_pos = (draw_start - WIN_HEIGHT / 2
			+ (WIN_HEIGHT / ray.perp_dist) / 2) * step;
	tex_x = wall_x * g->map.textures.ea.width;
	tex_x = g->map.textures.ea.width - tex_x - 1;
	while (draw_start <= draw_end)
	{
		tex_y = (int)tex_pos;
		put_pixel(&g->frame_buffer, ray.x, draw_start,
			get_color_from_texture(g->map.textures.ea, tex_x, tex_y));
		tex_pos += step;
		draw_start++;
	}
}
