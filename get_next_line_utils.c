/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:03:41 by oel-mado          #+#    #+#             */
/*   Updated: 2024/11/18 18:43:08 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (size > 0 && count >= SIZE_MAX / size)
		return (NULL);
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	if (size == 0 || count == 0)
		return (ptr);
	else
	{
		while (i < (count * size))
			((unsigned char *)ptr)[i++] = (unsigned char)0;
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = ft_calloc(sizeof(char), i);
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)s1, i);
	ft_strlcat(str, (char *)s2, i);
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (src[i] && i + 1 < n)
	{
		dst[i] = src[i];
		i++;
	}
	if (n > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (!dst && !n)
		return (ft_strlen(src));
	k = ft_strlen((const char *)dst);
	if (n < ft_strlen(dst))
		return (ft_strlen(src) + n);
	while (dst[i] && i + 1 < n)
		i++;
	while (src[j] && i + j + 1 < n)
	{
		dst[i + j] = src[j];
		j++;
		dst[i + j] = '\0';
	}
	return (k + ft_strlen(src));
}

size_t	ft_strlen(const char *who)
{
	size_t	ask;

	ask = 0;
	while (who[ask])
		ask++;
	return (ask);
}
