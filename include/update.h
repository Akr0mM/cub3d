/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 21:27:15 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/29 04:53:24 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_H
# define UPDATE_H

# include "cub3d.h"
# include "math.h"

void	update_game(t_game *g);
int		is_wall(t_game *g, double x, double y);
int		can_move_to(t_game *g, double x, double y);
void	check_correct_pos(t_game *g, t_vec2 new_pos);
void	dda(t_game *g, t_ray *ray);

#endif