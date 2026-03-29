/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 22:09:41 by mfaivre           #+#    #+#             */
/*   Updated: 2026/03/29 05:03:56 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->addr + y * img->line_len
		+ x * img->bpp / 8;
	*(unsigned int *)dst = (unsigned int)color;
}
