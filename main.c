#include "get_next_line.h"

// int main()
// {
//     char *str;
//     int fd = open("brainrot.txt", O_RDWR);
//     str = get_next_line(fd);
//     printf("result = %s\n", str);
//     free(str);
//     str = get_next_line(fd);
//     printf("result = %s\n", str);
//     free(str);
//     str = get_next_line(fd);
//     printf("result = %s\n", str);
//     free(str);
//     str = get_next_line(fd);
//     printf("result = %s\n", str);
//     free(str);
//     str = get_next_line(fd);
//     printf("result = %s\n", str);
//     free(str);
//     str = get_next_line(fd);
//     printf("result = %s\n", str);
//     free(str);
//     // int a = read(fd, NULL, 4);
//     // printf("%d\n", a);
//     close(fd);
// }



int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    printf("bda\n");
    while (line = get_next_line(fd))
    {
        printf("Str :\n");
        if (!printf("%s", line))
            printf("\nMakaynx\n");
        else
            printf("\nKyn\n");
        free(line);
    }
    printf("sala\n");
    close(fd);
    return (0);
}
