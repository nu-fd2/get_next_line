#include "get_next_line.h"

int main()
{
    char *str;
int fd = open("brainrot.txt", O_RDWR);
str = get_next_line(fd);
printf("result = %s\n", str);
free(str);
str = get_next_line(fd);
printf("result = %s\n", str);
free(str);
str = get_next_line(fd);
printf("result = %s\n", str);
free(str);
str = get_next_line(fd);
printf("result = %s\n", str);
free(str);
str = get_next_line(fd);
printf("result = %s\n", str);
free(str);
str = get_next_line(fd);
printf("result = %s\n", str);
free(str);
// int a = read(fd, NULL, 4);
// printf("%d\n", a);
close(fd);
}


// #include <fcntl.h>
// #include <stdio.h>

// int main(void)
// {
//     int fd = open("test.txt", O_RDONLY);
//     char *line;

//     while ((line = get_next_line(fd)))
//     {
//         printf("%s", line);
//         free(line);
//     }
//     close(fd);
//     return (0);
// }
