/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfantine <bfantine@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:10:27 by bfantine          #+#    #+#             */
/*   Updated: 2025/11/06 13:04:19 by bfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*create_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	bytes_read = 1;
	if (!buffer)
		return ((void *)0);
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return ((void *)0);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}
//pega inicio da stash ate o primeiro \n e devolve como uma string

static char	*get_line(char *stash)
{
	int	i;
	int	j;
	char	*line;

	i = 0;
	j = 0;
	if (!stash)
		return ((void *)0);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return ((void *)0);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		line[i++] = stash[i++];
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*remove_stash_line(char *stash)
{
	int	i;
	char	*new_stash;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return ((void *)0);
	}
	new_stash = malloc((ft_strlen(stash)) - i + 1);
	if (!new_stash)
		return ((void *)0);
	i++;
	while (stash[i])	
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[OPEN_MAX];

	if (fd < 0 ||fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return ((void *)0);
	stash[fd] = create_stash(fd, stash[fd]);
	if (!stash[fd])
		return ((void *)0);
	line = get_line(stash[fd]);
	stash[fd] = remove_stash_line(stash[fd]);
	return (line);
}
