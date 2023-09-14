/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:52:10 by kryrodri          #+#    #+#             */
/*   Updated: 2023/08/31 11:17:49 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> // O_RDONLY
// #include "get_next_line.h"
#include <unistd.h> // read
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char **argv)
{
    int fd = open(".archivo.txt", O_RDONLY);
  
    char *lectura = malloc(sizeof(char) * 50 + 1);
    
    
    int q_chars = read(fd, lectura, 50);
    // return:
    // Q de leido
    // 0 si llega al final
    // -1 si hay algun error de lectura

    lectura[q_chars] = '\0';
    printf("%s, %d\n", "1- lectura", q_chars);
    printf("%s\n", lectura);

    q_chars = read(fd, lectura, 50);
    lectura[q_chars] = '\0';
    printf("%s, %d\n", "2- lectura", q_chars);
    printf("%s", lectura); 
    
    q_chars = read(fd, lectura, 50);
    lectura[q_chars] = '\0';
    printf("\n%s, %d\n", "3- lectura", q_chars);
    printf("%s", lectura);

    // // get_next_line(fd);
    close(fd);

    // Buscando el error:
    q_chars = read(fd, lectura, 50);
    lectura[q_chars] = '\0';
    printf("\n%s, %d\n", "4- lectura", q_chars);
    printf("%s", lectura);


    free(lectura);
    return (0);
}