/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:04:15 by oel-mado          #+#    #+#             */
/*   Updated: 2024/12/14 06:53:22 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *rdd(char *buff, int fd)
{
	int i;
	char *yup;

	yup = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!yup)
		return (NULL);
	i = 1;
	while (!ft_strchr(yup, '\n') && i != 0)
	{
		i = read(fd, yup, BUFFER_SIZE);
		if (i < 0)
		{
			free(yup);
			return (NULL);
		}
		yup[i] = '\0';
		buff = ft_strjoin(buff, yup);
		if (!buff)
		{
			free(yup);
			return (NULL);
		}
	}
	free(yup);
	return (buff);
}

static char *one_line(const char *buff)
{
	size_t i;
	char *lain;

	lain = NULL;
	i = 0;
	if (!buff || buff[i] == '\0')
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	lain = ft_calloc(i + 2, 1);
	if (!lain)
		return (NULL);
	ft_strlcpy(lain, buff, i + 2);
	return (lain);
}

static char *updtt(char *buff)
{
	size_t i;
	size_t j;
	char *neo;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
	{
		free(buff);
		return (NULL);
	}
	j = ft_strlen(buff + i + 1);
	neo = ft_calloc(j + 1, 1);
	if (!neo)
	{
		free(buff);
		return (NULL);
	}
	ft_strlcpy(neo, buff + i + 1, j + 1);
	free(buff);
	return (neo);
}

char *get_next_line(int fd)
{
	static char *buff;
	char *lain;

	lain = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, buff, 0) == -1)
		return(NULL);
	buff = rdd(buff, fd);
	if(!buff)
		return (NULL);
	lain = one_line(buff);
	if (!lain)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	buff = updtt(buff);
	return (lain); 
}
