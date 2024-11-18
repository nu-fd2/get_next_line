/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 11:04:15 by oel-mado          #+#    #+#             */
/*   Updated: 2024/11/18 18:39:13 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char ptr[10];
    static char *str;
    char *p;
    short X;
    ssize_t siz;
    size_t i = 0;
    size_t j = 0;

    X = 0;
    while (!X)
    {
        siz = read(fd, ptr, 10);
        if (!siz)
            return (NULL);
        if (!ft_memchr(ptr, '\n', 10))
            str = ft_strjoin(str, ptr);
        else
        {
            
            X = 1;
        }
            
    }
    
    printf("size = %zd\n", siz);
    printf("ptr = %s\n", ptr);
    printf("bfr = %s\n", str);
    return (str);
}






void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
