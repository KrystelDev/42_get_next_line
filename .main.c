#include <fcntl.h> // O_RDONLY
#include "get_next_line.h"
#include <unistd.h> // read
#include <stdio.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5

#endif

int main(void)
{
    int fd = open("1char.txt", O_RDONLY);
    char *line = "star";
    int i = 1;
    while (line != NULL)
    {
        line = get_next_line(fd);
        printf("%d-linea\n", i);
        printf("%s", line);
        i++;
    }
    close(fd);
    return (0);
}