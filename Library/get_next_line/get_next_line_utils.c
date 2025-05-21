/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:55:42 by tripham           #+#    #+#             */
/*   Updated: 2025/05/18 23:04:54 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(char *s1)
{
	char	*s2;
	size_t	len;
	size_t	i;

	if (!s1)
		return (NULL);
	i = 0;
	len = ft_strlen_gnl(s1);
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

size_t	ft_strlen_gnl(char *s1)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy_gnl(void *des, const void *src, size_t len)
{
	size_t		i;
	char		*destination;
	const char	*source;

	i = 0;
	destination = (char *)des;
	source = (const char *)src;
	if (!destination && !source)
		return (NULL);
	if (des == src)
		return (des);
	if (des != src)
	{
		while (i < len)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (des);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (ft_strdup_gnl(""));
	if (!s1)
		return (ft_strdup_gnl(s2));
	if (!s2)
		return (ft_strdup_gnl(s1));
	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	res = malloc((sizeof(char)) * (s1_len + s2_len + 1));
	if (!res)
		return (NULL);
	ft_memcpy_gnl(res, s1, s1_len);
	ft_memcpy_gnl((res + s1_len), s2, s2_len);
	res[s1_len + s2_len] = '\0';
	free (s1);
	return (res);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int		i;
	char	chr;

	i = 0;
	chr = c;
	while (s[i])
	{
		if (s[i] == chr)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == chr)
		return ((char *)&s[i]);
	return (NULL);
}
