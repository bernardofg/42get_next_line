/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfantine <bfantine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:44:00 by bfantine          #+#    #+#             */
/*   Updated: 2025/11/06 13:45:29 by bfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		line_count;

	fd = open("test1.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erro ao abrir o arquivo");
		return (1);
	}
	line_count = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Linha %d: %s", line_count, line);
		free(line);
		line_count++;
	}
	close(fd);
	return (0);
}
