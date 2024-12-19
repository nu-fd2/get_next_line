#include "get_next_line.h"
#include "../ft_printf/src/ft_printf.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
    int		fd;
    char	*line;

    fd = open("txt.txt", O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        ft_printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}