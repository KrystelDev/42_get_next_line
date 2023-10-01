/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:45:07 by kryrodri          #+#    #+#             */
/*   Updated: 2023/10/01 15:53:29 by kryrodri         ###   ########.fr       */
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

//  void	*ft_calloc(int num_elements, int element_size)
// {
// 	char	*copia_cpy;
//     int	i;

// 	copia_cpy = malloc(num_elements * element_size);
// 	if (copia_cpy == NULL)
// 	{
// 		return (NULL);
// 	}
// 	i = 0;
// 	while (i < num_elements * element_size)
// 	{
// 		((char *)copia_cpy)[i] = '\0';
// 		i++;
// 	}
// 	return (copia_cpy);
// }
// reading = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));

 void ft_clean(char **brut)
 {
	free(*brut);
	*brut = NULL;
 }

char *get_next_line(int fd)
{
    static char *reading = NULL; // que ha leido read (quizá deberia inicializar en otra función).
    int q_chars; // que devuelve read (quizá deberia inicializar en otra función).
    // int i_line; // para localizar el salto de linea. (quizá deberia inicializar en otra función).
    char *result;
    
    result = NULL; // lo que devuelve la función principal.

// Controlo el error de open.
    if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, 0,0)))
        return (NULL);

// 1- Hay algo pendiente a devolver ? >> while hasta que sea Sí o Nada que leer
    while (!reading) //    while (!reading || !q_chars)
    {
        reading = malloc(BUFFER_SIZE + 1);
        if(!reading)
        {
            // if (result)
            // {
            //     ft_clean(&result);
            // }
            return (NULL);
        }
    // 1-2 No pendiente ->
            // Lee
        q_chars = read(fd, reading, BUFFER_SIZE);
        reading[q_chars] = '\0';
    }

    // Si pongo esto salta mas errores.. T-T
    // if (q_chars <= 0) 
    // {
    //     // -1 si hay algun error de reading
    //     return (NULL);
    // }

    // 1-1 Sí pendiente -> Hay '\n' en lo pendiente ? >> while hasta que sea Sí o Nada que leer
    while (ft_look_for_line(reading)== -1 && q_chars != 0)
    {
        // No -> Concatena lo pendiente con una nueva lectura y vuelve al punto 1.1
        result = ft_strjoin(result, reading);
        if(!result)
            return (NULL);
        ft_clean(&reading);
        
        // "volver al punto 1.1"
            while (!reading) //    while (!reading || !q_chars)
            {
                reading = malloc(BUFFER_SIZE + 1);
                if(!reading)
                    return (NULL);
            // 1-2 No pendiente ->
                    // Lee
                q_chars = read(fd, reading, BUFFER_SIZE);
                if (q_chars == -1) 
                {
                    // -1 si hay algun error de reading
                    return NULL;
                }
                if (q_chars == 0 && result) // Sí -> Guarda en result desde el inicio de pendiente hasta el final.
                {
                    ft_clean(&reading);
                    if(result && result[0] == '\0')
                        return(NULL);
                    return (result);
                }
                reading[q_chars] = '\0';
            }
    }
        // Sí -> Guarda en result desde el inicio de pendiente hasta el '\n'
    if (ft_look_for_line(reading) != -1)
    {
        result = ft_strjoin(result, ft_substr(reading, 0, ft_look_for_line(reading)+1));
        if (!result)
        {
            return (NULL);
        }
        reading = ft_substr(reading, ft_look_for_line(reading)+1, ft_strlen(reading)-1);
      
    }
    if (q_chars == 0)
        ft_clean(&reading);
    if(result && result[0] == '\0')
        return(NULL);
    return (result);
}