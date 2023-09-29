/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:52:10 by kryrodri          #+#    #+#             */
/*   Updated: 2023/09/28 18:39:02 by kryrodri         ###   ########.fr       */
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
	char *line = "star";
	int	i = 1;
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%d-linea\n", i);
		printf("%s\n", line);
		i++;
	}
	close(fd);
	return (0);
}