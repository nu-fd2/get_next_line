#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#include <limits.h>
#include <stdio.h>
#include <fcntl.h>

ssize_t get_next_line(int fd);

#endif //GET_NEXT_LINE_H