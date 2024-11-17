#include "get_next_line.h"

int main() {
    char buffer[120];
    int fd = open("test.txt", O_RDONLY); // Open a file for reading
    int fd2 = open("test.txt", O_WRONLY); // Open a file for reading
    //int fd3 = open("test.txt", O_RDWR); // Open a file for reading
    int n;

    n = 3;
    write(fd, "aaa", 3);
    write(fd2, "n", 1);
    printf("%d\n%d\n", fd, fd2);

    // write(0, "b", 1);
    // printf("%d\n", fd2);
    // write(2, "d", 1);
    // printf("%d\n", fd3);


    // if (fd == -1) {
    //     perror("Error opening file");
    //     return 1;
    // }

    // ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    // if (bytesRead == -1) {
    //     perror("Error reading file");
    //     close(fd);
    //     return 1;
    // }

    // buffer[bytesRead] = '\0'; // Null-terminate the buffer
    // printf("Read %ld bytes: %s\n", bytesRead, buffer);

    // close(fd);
    // fd++;
    // write(n, "sssss", 5);
    // printf("%d\n", fd);
    // printf("%d\n", n);
    return 0;
}
