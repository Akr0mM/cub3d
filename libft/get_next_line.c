/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:23:21 by mfaivre           #+#    #+#             */
/*   Updated: 2025/12/12 01:21:04 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*buffer;
	int				size;
	int				end;

	if (fd < 0 || BUFFER_SIZE <= 0 || !init_buffer(&buffer))
		return (free_all(&stash, NULL));
	if (!stash && !init_stash(&stash))
		return (free_all(&stash, &buffer));
	end = 0;
	while (new_line_char(stash) < 0 && !end)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
			return (free_all(&stash, &buffer));
		if (size == 0)
			end = 1;
		else if (!add_to_stash(&stash, buffer, size))
			return (free_all(&stash, &buffer));
	}
	free(buffer);
	if (!stash || ft_strlen(stash) == 0)
		return (free_all(&stash, NULL));
	return (get_return_line(&stash));
}

char	*get_return_line(char **stash)
{
	char	*line;
	int		i;
	int		line_len;

	line_len = new_line_char(*stash);
	if (line_len >= 0)
		line_len += 1;
	else
		line_len = ft_strlen(*stash);
	line = malloc(line_len + 1);
	if (!line)
		return (free_all(stash, NULL));
	i = 0;
	while (i < line_len)
	{
		line[i] = (*stash)[i];
		i++;
	}
	line[i] = '\0';
	if (!reduce_stash(stash, line_len))
	{
		free(line);
		return (free_all(stash, NULL));
	}
	return (line);
}

int	reduce_stash(char **stash, int line_len)
{
	int		i;
	int		new_len;
	char	*new_stash;

	new_len = ft_strlen(*stash + line_len);
	if (new_len == 0)
	{
		free(*stash);
		*stash = NULL;
		return (1);
	}
	new_stash = malloc(new_len + 1);
	if (!new_stash)
		return (0);
	i = 0;
	while (i < new_len)
	{
		new_stash[i] = (*stash)[i + line_len];
		i++;
	}
	new_stash[i] = '\0';
	free(*stash);
	*stash = new_stash;
	return (1);
}

int	add_to_stash(char **stash, char *buffer, int size)
{
	char	*new_stash;
	int		cur_len;
	int		i;
	int		j;

	cur_len = ft_strlen(*stash);
	new_stash = malloc(cur_len + size + 1);
	if (!new_stash)
		return (0);
	i = 0;
	j = 0;
	while (i < cur_len)
	{
		new_stash[i] = (*stash)[i];
		i++;
	}
	while (j < size)
	{
		new_stash[i + j] = buffer[j];
		j++;
	}
	new_stash[i + j] = '\0';
	free(*stash);
	*stash = new_stash;
	return (1);
}
