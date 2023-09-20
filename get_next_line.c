/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:45:07 by kryrodri          #+#    #+#             */
/*   Updated: 2023/09/20 18:09:03 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 1- Hay algo pendiente a devolver ? >> while hasta que sea Sí o Nada que leer
    // 1-1 Sí pendiente -> Hay '\n' en lo pendiente ? >> while hasta que sea Sí o Nada que leer
            // Sí -> Guarda en result desde el inicio de pendiente hasta el '\n'
            // No -> Concatena lo pendiente con una nueva lectura y vuelve al punto 1.1
    // 1-2 No pendiente -> 
            // Lee
            // Guarda en pendiente
            // vuelve al punto 1

char *get_next_line(int fd)
{
    static char *reading = NULL;; // que ha leido read (quizá deberia inicializar en otra función).
    int q_chars; // que devuelve read (quizá deberia inicializar en otra función).
    // int i_line; // para localizar el salto de linea. (quizá deberia inicializar en otra función).
    static char *result = NULL; // lo que devuelve la función principal.

// Controlo el error de open.
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

// 1- Hay algo pendiente a devolver ? >> while hasta que sea Sí o Nada que leer
    while (!reading)
    {
        reading = malloc(BUFFER_SIZE + 1);
    // 1-2 No pendiente ->
            // Lee
        q_chars = read(fd, reading, BUFFER_SIZE);
        if (q_chars <= 0) 
        {
            // -1 si hay algun error de reading
            return NULL;
        }
        if (q_chars)
        {
            reading[q_chars] = '\0';
        }

    }
    // 1-1 Sí pendiente -> Hay '\n' en lo pendiente ? >> while hasta que sea Sí o Nada que leer
    while (ft_look_for_line(reading)== -1 && q_chars != 0)
    {
        // No -> Concatena lo pendiente con una nueva lectura y vuelve al punto 1.1
        result = ft_strjoin(result, reading);
    }
        // Sí -> Guarda en result desde el inicio de pendiente hasta el '\n'
    if (ft_look_for_line(reading) != -1)
    {
        result = ft_substr(reading, 0, ft_look_for_line(reading));
        reading = ft_substr(reading, ft_look_for_line(reading), ft_strlen(reading));
    }
    if (q_chars == 0) // Sí -> Guarda en result desde el inicio de pendiente hasta el final.
    {
        result = "\0";
        free(reading);
    }
    
    return (result);
}