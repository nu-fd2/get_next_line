/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:04:15 by oel-mado          #+#    #+#             */
/*   Updated: 2024/12/01 08:57:11 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *neo(char *buff, int fd)
{
	char *neo;
	size_t i;

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

static size_t rei(const char *buff, char *lain, size_t i)
{
	if (buff[i] == '\0')
		return (0);
	while (buff[i] != '\n')
		i++;
	lain = ft_calloc(i + 1, 1);
	if (i != 0)
		ft_strlcpy(lain, buff, i);
	return (i);
}

char *get_next_line(int fd)
{
	static char *buff;
	char *lain;
	char *miku;
	size_t re_l;

	re_l = 0;
	lain = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return(NULL);
	buff = neo(buff, fd);
	re_l = rei(buff, lain, re_l);
	ft_strlcpy(miku, lain, re_l);
	free(lain);
	buff = &buff[re_l];
	return (miku);
}
