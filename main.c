#include "get_next_line.h"

int main(void)
{
    int fd = open("skibidi.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    char *line = NULL;

    printf("fd  = %d\n", fd);
    // while ((line = get_next_line(fd)) != NULL)
    // {
    //     printf("Str :\n");
    //     if (!printf("%s", line))
    //         printf("\nMakaynx\n");
    //     else
    //         printf("\nKyn\n");
    //     free(line);
    // }
    line = get_next_line(fd);
    printf("%s\n", line);
    line = get_next_line(fd);
    printf("%s\n", line);
    line = get_next_line(fd);
    printf("%s\n", line);
    line = get_next_line(fd);
    printf("%s\n", line);
    printf("sala\n");
    close(fd);
    return (0);
}
