/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:04:15 by oel-mado          #+#    #+#             */
/*   Updated: 2024/12/09 00:32:04 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *rdd(char *buff, int fd)
{
	char *yup;
	char *neo;
	int i;

	yup = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!yup)
		return (NULL);
	i = read(fd, yup, BUFFER_SIZE);
	if (i == -1)
	{
		free(yup);
		return (NULL);
	}
	if (i == 0)
	{
		free(yup);
		if (!buff)
			return (NULL);
		return (buff);
	}
	if (!buff)
		neo = ft_strdup(yup);
	else
		neo = ft_strjoin(buff, yup);
	if (!neo)
	{
		free(yup);
		free(buff);
		buff = NULL;
		return (NULL);
	}
	free(yup);
	free(buff);
	buff = NULL;
	return (neo);
}

static char *one_line(const char *buff, char *lain)
{
	size_t i;

	i = 0;
	if (buff[i] == '\0')
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	lain = ft_calloc(i + 1, 1);
	if (!lain)
		return (NULL);
	if (i != 0)
		ft_strlcpy(lain, buff, i + 1);
	return (lain);
}

static char *updtt(char *buff)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	j = ft_strlen(&buff[i]);
	if (buff[i] == '\0' || j == 0)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	ft_memmove(buff, &buff[i + 1], j + 1);
	return (buff);
}

char *get_next_line(int fd)
{
	static char *buff;
	char *lain;

	lain = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return(NULL);
	buff = rdd(buff, fd);
	lain = one_line(buff, lain);
	if (!lain)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	buff = updtt(buff);
	return (lain);
}
