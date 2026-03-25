/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:08:30 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/25 11:43:39 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
#include "map.h"

int	main(int ac, char **av)
{
	t_game	g;

	parse_and_validate(&g, ac, av);
	destroy_all(&g);
	return (0);
}

void	destroy_all(t_game *g)
{
	destroy_map(&g->map, NULL);
}
