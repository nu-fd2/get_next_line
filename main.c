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
    //         printf("\nKysn\n");
    //     free(line);
    // }
    line = get_next_line(fd);
    printf("1 %s", line);
    line = get_next_line(fd);
    printf("2 %s", line);
    line = get_next_line(fd);
    printf("3 %s", line);
    line = get_next_line(fd);
    printf("4 %s", line);

    close(fd);
    return (0);
}



// int main(void)
// {
//     int fd = open("skibidi.txt", O_RDONLY);
//     char *line;

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("Line: %s", line);
//         free(line);
//     }

//     close(fd);
//     return 0;
// }


