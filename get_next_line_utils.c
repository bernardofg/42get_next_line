/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfantine <bfantine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:56:18 by bfantine          #+#    #+#             */
/*   Updated: 2025/11/06 13:31:35 by bfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	sizes1;
	size_t	sizes2;
	char	*res;

	i = 0;
	sizes1 = ft_strlen(s1);
	sizes2 = ft_strlen(s2);
	res = malloc(sizes1 + sizes2 +1);
	if (!res)
		return ((void *)0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[sizes1 + i] = s2[i];
		i++;
	}
	res[sizes1 + i] = '\0';
	free(s1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	char	*str;

	str = (char *) s;
	i = 0;
	if (!s)
		return ((void *)0);
	while (str[i])
	{
		i++;
		if (str[i] == c)
			return (&str[i]);
	}
	return (0);
}
