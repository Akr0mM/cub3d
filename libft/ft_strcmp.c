/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:44:27 by maxime            #+#    #+#             */
/*   Updated: 2026/03/03 18:44:47 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t				i;
	int					diff;
	const unsigned char	*ucs1;
	const unsigned char	*ucs2;

	i = 0;
	ucs1 = (const unsigned char *)s1;
	ucs2 = (const unsigned char *)s2;
	while ((ucs1[i] || ucs2[i]))
	{
		diff = (ucs1)[i] - (ucs2)[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}
