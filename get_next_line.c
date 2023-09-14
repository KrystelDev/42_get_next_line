/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:45:07 by kryrodri          #+#    #+#             */
/*   Updated: 2023/09/14 15:02:59 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *reading; // que ha leido read (quizá deberia inicializar en otra función).
    int q_chars; // que devuelve read (quizá deberia inicializar en otra función).
    int i_line; // para localizar el salto de linea.
    static char *result = NULL; // lo que devuelve la función principal.


    
    return result;
}