/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:08:30 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/29 01:19:47 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
#include "map.h"
#include "mlx.h"
#include "render.h"
#include "update.h"

int	main(int ac, char **av)
{
	t_game	g;

	g.mlx = NULL;
	g.win = NULL;
	g.keys = (t_keys){0};
	parse_and_validate(&g, ac, av);
	init_mlx(&g);
	mlx_loop(g.mlx);
	destroy_all(&g, NULL);
	return (0);
}

int	game_loop(t_game *g)
{
	update_game(g);
	render_frame(g);
	return (0);
}

void	destroy_all(t_game *g, char *err)
{
	destroy_map(&g->map, NULL);
	destroy_mlx(g);
	if (err)
		print_error(err);
}

void	print_error(char *err)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	print_perror(char *err)
{
	ft_putstr_fd("Error\n", 2);
	perror(err);
	exit(1);
}
