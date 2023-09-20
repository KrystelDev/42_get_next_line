/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:52:10 by kryrodri          #+#    #+#             */
/*   Updated: 2023/09/20 16:44:54 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> // O_RDONLY
// #include "get_next_line.h"
#include <unistd.h> // read
#include <stdio.h>
#include <stdlib.h>


int main (void)
{
    int fd = open(".archivo.txt", O_RDONLY);
  
    char *lectura = malloc(sizeof(char) * 50 + 1);
    
    
    int q_chars = read(fd, lectura, 50);
    // return:
    // Q de leido
    // 0 si llega al final -> que sigui 0, no implica que no hagi llegit res
    // -1 si hay algun error de lectura

    lectura[q_chars] = '\0';
    printf("%s, %d\n", "1- lectura", q_chars);
    printf("%s\n", lectura);

    q_chars = read(fd, lectura, 10);
    lectura[q_chars] = '\0';
    printf("%s, %d\n", "2- lectura", q_chars);
    printf("%s", lectura); 
    
    // q_chars = read(fd, lectura, 10);
    // lectura[q_chars] = '\0';
    // printf("\n%s, %d\n", "3- lectura", q_chars);
    // printf("%s", lectura);

    // // // get_next_line(fd);
    // close(fd);

    // // Buscando el error:
    // q_chars = read(fd, lectura, 10);
    // lectura[q_chars] = '\0';
    // printf("\n%s, %d\n", "4- lectura", q_chars);
    // printf("%s", lectura);


    free(lectura);
    return (0);
}