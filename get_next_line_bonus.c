/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfantine <bfantine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:44:32 by bfantine          #+#    #+#             */
/*   Updated: 2025/11/12 14:47:52 by bfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*create_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	readed;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!(buffer))
		return ((void *)0);
	readed = 1;
	while (!ft_strchr(stash, '\n') && readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed < 0)
		{
			free(buffer);
			return (free(stash), (void *)0);
		}
		buffer[readed] = '\0';
		if (readed > 0)
			stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

static char	*get_line(const char *stash)
{
	size_t	i;
	char	*line;

	if (!stash || !*stash)
		return ((void *)0);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + (stash[i] == '\n') + 1);
	if (!line)
		return ((void *)0);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*remove_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), (void *)0);
	new_stash = malloc(ft_strlen(stash + i + 1) + 1);
	if (!new_stash)
		return (free(stash), (void *)0);
	j = 0;
	while (stash[++i])
		new_stash[j++] = stash[i];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = create_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = get_line(stash[fd]);
	stash[fd] = remove_stash(stash[fd]);
	return (line);
}
