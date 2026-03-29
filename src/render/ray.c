/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 04:52:10 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/29 04:52:45 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	init_ray(t_game *g, t_ray *ray, int x)
{
	ray->camera_x = 2.0 * x / (double)WIN_WIDTH - 1.0;
	ray->ray.x = g->cam.dir.x + g->cam.plane.x * ray->camera_x;
	ray->ray.y = g->cam.dir.y + g->cam.plane.y * ray->camera_x;

	ray->map_x = (int)g->cam.pos.x;
	ray->map_y = (int)g->cam.pos.y;

	if (ray->ray.x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1.0 / ray->ray.x);
	if (ray->ray.y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1.0 / ray->ray.y);
}

void	init_dist(t_game *g, t_ray *ray)
{
	if (ray->ray.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (g->cam.pos.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - g->cam.pos.x)
			* ray->delta_dist_x;
	}
	if (ray->ray.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (g->cam.pos.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - g->cam.pos.y)
			* ray->delta_dist_y;
	}
}

void	dda(t_game *g, t_ray *ray)
{
	ray->hit = 0;
	while (!ray->hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (g->map.grid[ray->map_y][ray->map_x] == 2)
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perp_dist = (ray->map_x - g->cam.pos.x
				+ (1 - ray->step_x) / 2.0) / ray->ray.x;
	else
		ray->perp_dist = (ray->map_y - g->cam.pos.y
				+ (1 - ray->step_y) / 2.0) / ray->ray.y;
}
