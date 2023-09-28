/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:52:10 by kryrodri          #+#    #+#             */
/*   Updated: 2023/09/28 13:33:43 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> // O_RDONLY
#include "get_next_line.h"
#include <unistd.h> // read
#include <stdio.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5

# endif

int main (void)
{
	int fd = open(".archivo.txt", O_RDONLY);
	// un while per veure com va fins el final.
	printf("1-linea\n");
	printf("%s\n", get_next_line(fd));
	printf("2-linea\n");
	printf("%s\n", get_next_line(fd));
	printf("3-linea\n");
	printf("%s\n", get_next_line(fd));

	close(fd);
	return (0);
}