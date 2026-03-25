/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:23:17 by mfaivre           #+#    #+#             */
/*   Updated: 2025/12/12 01:20:58 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	new_line_char(char *stash)
{
	int	i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	init_stash(char **stash)
{
	*stash = malloc(1);
	if (!*stash)
		return (0);
	(*stash)[0] = '\0';
	return (1);
}

int	init_buffer(char **buffer)
{
	*buffer = malloc(BUFFER_SIZE);
	if (!*buffer)
		return (0);
	return (1);
}

char	*free_all(char **stash, char **buffer)
{
	if (stash && *stash)
	{
		free(*stash);
		*stash = NULL;
	}
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}
