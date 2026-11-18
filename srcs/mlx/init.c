/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 20:50:03 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/29 00:55:32 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map.h"

static int	handle_close(t_game *game);
static int	handle_key_press(int keysym, t_game *g);
static int	handle_key_release(int keysym, t_game *g);

void	init_mlx(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		destroy_map(&g->map, "mlx_init() failed");
	g->win = mlx_new_window(g->mlx,
			WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!g->win)
		destroy_all(g, "mlx_new_window failed");
	mlx_hook(g->win, KeyPress, KeyPressMask, &handle_key_press, g);
	mlx_hook(g->win, KeyRelease, KeyReleaseMask, &handle_key_release, g);
	mlx_hook(g->win, DestroyNotify, StructureNotifyMask,
		&handle_close, g);
	mlx_loop_hook(g->mlx, game_loop, g);
	load_textures(g);
	g->frame_buffer.width = WIN_WIDTH;
	g->frame_buffer.height = WIN_HEIGHT;
	g->frame_buffer.img = mlx_new_image(g->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!g->frame_buffer.img)
		destroy_all(g, "mlx_new_image failed");
	g->frame_buffer.addr = mlx_get_data_addr(
			g->frame_buffer.img,
			&g->frame_buffer.bpp,
			&g->frame_buffer.line_len,
			&g->frame_buffer.endian);
}

static int	handle_close(t_game *game)
{
	destroy_all(game, NULL);
	exit(0);
	return (0);
}

static int	handle_key_press(int keysym, t_game *g)
{
	if (keysym == XK_Escape)
		handle_close(g);
	else if (keysym == XK_w)
		g->keys.w = 1;
	else if (keysym == XK_a)
		g->keys.a = 1;
	else if (keysym == XK_s)
		g->keys.s = 1;
	else if (keysym == XK_d)
		g->keys.d = 1;
	else if (keysym == XK_Left)
		g->keys.l = 1;
	else if (keysym == XK_Right)
		g->keys.r = 1;
	return (0);
}

static int	handle_key_release(int keysym, t_game *g)
{
	if (keysym == XK_w)
		g->keys.w = 0;
	else if (keysym == XK_a)
		g->keys.a = 0;
	else if (keysym == XK_s)
		g->keys.s = 0;
	else if (keysym == XK_d)
		g->keys.d = 0;
	else if (keysym == XK_Left)
		g->keys.l = 0;
	else if (keysym == XK_Right)
		g->keys.r = 0;
	return (0);
}

void	destroy_mlx(t_game *g)
{
	if (g->frame_buffer.img)
		mlx_destroy_image(g->mlx, g->frame_buffer.img);
	if (g->map.textures.no.img)
		mlx_destroy_image(g->mlx, g->map.textures.no.img);
	if (g->map.textures.so.img)
		mlx_destroy_image(g->mlx, g->map.textures.so.img);
	if (g->map.textures.we.img)
		mlx_destroy_image(g->mlx, g->map.textures.we.img);
	if (g->map.textures.ea.img)
		mlx_destroy_image(g->mlx, g->map.textures.ea.img);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	g->win = NULL;
	g->mlx = NULL;
}
