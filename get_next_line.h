#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#include <limits.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

char    *get_next_line(int fd);

// void	*ft_calloc(size_t count, size_t size);
// void	*ft_memchr(const void *s, int c, size_t n);
// char	*ft_strjoin(char const *s1, char const *s2);
// size_t	ft_strlcpy(char *dst, const char *src, size_t n);
// size_t	ft_strlcat(char *dst, const char *src, size_t n);
// size_t	ft_strlen(const char *who);

#endif //GET_NEXT_LINE_H 