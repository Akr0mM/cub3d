/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 11:21:24 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/25 14:06:17 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	map_error(char *err)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	map_perror(char *err)
{
	ft_putstr_fd("Error\n", 2);
	perror(err);
	exit(1);
}

void	destroy_map(t_map *map, char *err)
{
	int	i;

	i = 0;
	while (map->lines[i])
	{
		free(map->lines[i]);
		i++;
	}
	if (err)
		map_error(err);
}

int	is_dir(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	valid_map_name(char *name)
{
	(void)name;
	return (1);
}
