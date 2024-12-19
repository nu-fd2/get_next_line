/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:04:15 by oel-mado          #+#    #+#             */
/*   Updated: 2024/12/19 01:30:03 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rdd(char *buff, int fd)
{
	int		i;
	char	*yup;
	char	*wait;

	yup = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!yup)
		return (NULL);
	i = 1;
	while (!ft_strchr(yup, '\n') && i != 0)
	{
		i = read(fd, yup, BUFFER_SIZE);
		if (i == -1)
			return (free(yup), yup = NULL, NULL);
		yup[i] = '\0';
		wait = buff;
		buff = ft_strjoin(buff, yup);
		if (!buff)
			return (free(yup), yup = NULL, free(wait), NULL);
		free(wait);
	}
	return (free(yup), yup = NULL, buff);
}

char	*one_line(const char *buff)
{
	size_t	i;
	char	*lain;

	lain = NULL;
	i = 0;
	if (!buff || buff[i] == '\0')
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
		i += 1;
	else
		i += 2;
	lain = ft_calloc(i, 1);
	if (!lain)
		return (NULL);
	ft_strlcpy(lain, buff, i);
	return (lain);
}

char	*updtt(char *buff)
{
	size_t	i;
	size_t	j;
	char	*neo;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
		return (free(buff), buff = NULL, NULL);
	j = ft_strlen(buff + i + 1);
	if (j <= 0)
		return (free(buff), buff = NULL, NULL);
	neo = ft_calloc(j + 1, 1);
	if (!neo)
		return (free(buff), buff = NULL, NULL);
	ft_strlcpy(neo, buff + i + 1, j + 1);
	return (free(buff), buff = NULL, neo);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*lain;

	lain = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, buff, 0) == -1)
	{
		if (buff)
			return (free(buff), buff = NULL, NULL);
		return (NULL);
	}
	buff = rdd(buff, fd);
	if (!buff)
		return (NULL);
	lain = one_line(buff);
	if (!lain)
		return (free(buff), buff = NULL, NULL);
	buff = updtt(buff);
	return (lain); 
}

char	*ft_strdup(const char *s1)
{
	size_t	ln;
	char	*s2;

	ln = ft_strlen(s1) + 1;
	s2 = malloc(sizeof(char) * ln);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, ln);
	return (s2);
}
