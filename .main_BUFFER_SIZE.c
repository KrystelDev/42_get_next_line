/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main_BUFFER_SIZE.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:52:10 by kryrodri          #+#    #+#             */
/*   Updated: 2023/09/04 15:18:56 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5

# endif

int main (void)
{
    printf("buffer %i", BUFFER_SIZE);
    return (0);
}

// cc -D BUFFER_SIZE=42 .main_BUFFER_SIZE.c
// imprimirá 42

// cc .main_BUFFER_SIZE.c
// imprimirá 5