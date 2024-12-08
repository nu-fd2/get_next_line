/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:04:15 by oel-mado          #+#    #+#             */
/*   Updated: 2024/12/08 10:30:49 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *rdd(char *buff, int fd)
{
	char *neo;
	int i;

	neo = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!neo)
		return (NULL);
	i = read(fd, neo, BUFFER_SIZE);
	if (i == -1)
	{
		free(neo);
		return (NULL);
	}
	buff = ft_strjoin(buff, neo);
	free(neo);
	return (buff);
}

static char *one_line(const char *buff, char *lain)
{
	size_t i;

	i = 0;
	if (buff[i] == '\0')
		return (0);
	while (buff[i] != '\n')
		i++;
	lain = ft_calloc(i + 1, 1);
	if (i != 0)
		ft_strlcpy(lain, buff, i);
	return (lain);
}

static char *updtt(char *buff)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (buff[i] == '\0')
		return (0);
	while (buff[i] != '\n')
		i++;
	j = ft_strlen(&buff[i]);
	if (j == 0)
	{
		free(buff);
		return (NULL);
	}
	ft_strlcpy(buff, &buff[i + 1], j);
	return (buff);
}

char *get_next_line(int fd)
{
	static char *buff;
	char *lain;
	char *miku;

	lain = NULL;
	miku = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return(NULL);
	buff = rdd(buff, fd);
	if (!buff)
		return (NULL);
	lain = one_line(buff, lain);
	if (!lain)
		return (NULL);
	buff = updtt(buff);
	return (lain);
}
