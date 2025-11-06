/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfantine <bfantine@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:56:18 by bfantine          #+#    #+#             */
/*   Updated: 2025/11/06 13:03:21 by bfantine         ###   ########.fr       */
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
		res[i++] = s1[i++];
	i = 0;
	while (s2[i])
		res[sizes1 + i++] = s2[i++];
	res[sizes1 + i] = '\0';
	free(s1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return ((void *)0);
	while (s[i])
	{
		i++;
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int	i;
	int	s1_len;
	char	*dest;

	i = 0;
	s1_len = ft_strlen(s1);
	dest = malloc(s1 + 1);
	if (!dest)
		return ((void *)0);
	while (s1)
		dest[i++] = s1[i++];
	dest[i] = 0;
	return (res);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char *str;

	if (!s)
		return ((void *)0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc(len + 1);
	if (!str)
		return ((void *)0);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
