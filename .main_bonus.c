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
    int fd1 = open(".archivo.txt", O_RDONLY);
    int fd2 = open(".archivo2.txt", O_RDONLY);
    char *line = "star";
    int i = 1;
    while (line != NULL)
    {
        line = get_next_line(fd1);
        printf("%d-linea\n", i);
        printf("%s", line);
        line = get_next_line(fd2);
        printf("%d-linea\n", i);
        printf("%s", line);

        i++;
    }
    close(fd1);
    return (0);
}