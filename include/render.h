/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 21:27:34 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/29 05:08:28 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# include <math.h>

void	render_frame(t_game *g);
void	put_pixel(t_img *img, int x, int y, int color);
void	init_ray(t_game *g, t_ray *ray, int x);
void	init_dist(t_game *g, t_ray *ray);
void	dda(t_game *g, t_ray *ray);
void	draw_vertical_line_north(t_game *g, t_ray ray,
			int draw_start, int draw_end);
void	draw_vertical_line_south(t_game *g, t_ray ray,
			int draw_start, int draw_end);
void	draw_vertical_line_west(t_game *g, t_ray ray,
			int draw_start, int draw_end);
void	draw_vertical_line_east(t_game *g, t_ray ray,
			int draw_start, int draw_end);

#endif