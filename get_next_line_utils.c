/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:45:27 by kryrodri          #+#    #+#             */
/*   Updated: 2023/09/29 19:23:37 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_look_for_line(char *s) // '\n' o '\0'
{
    int i_line;
    
    i_line = 0;

    while (s[i_line] != '\0' && s[i_line] != '\n')
        (i_line)++;
    if (s[i_line] != '\n')
        i_line = -1; // No se encontró el '\n'
	return (i_line);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_string;
	size_t	i;
    
	new_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_string)
	{
		// ft_clean(&s2);
		return (NULL);
	}
	i = 0;
	while (s1 && s1[i])
	{
		new_string[i] = s1[i];
		i++;
	}
	while (s2 && *s2)
	{
		new_string[i] = *s2;
		i++;
		s2++;
	}
	new_string[i] = '\0';
	// if(s2)
	// 	ft_clean(&s2);
	return (new_string);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*new_string;

// 	new_string = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
// 	if (new_string == NULL)
// 		return (NULL);
// 	ft_strlcat(new_string, s1, ft_strlen(s1) + 1);
// 	ft_strlcat(new_string, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
// 	return (new_string);
// }

 char	*ft_substr(char *s, size_t start, size_t len)
{	
	char	*result;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (i < start)
		return (NULL);
	i = 0;
	while (s[i + start])
		i++;
	if (i < len)
		result = malloc(sizeof(char) * (i + 1));
	else
		result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*substring;

// 	if (start >= ft_strlen(s))
// 		return (ft_strdup(""));
// 	s += start;
// 	if (len > ft_strlen(s))
// 		len = ft_strlen(s);
// 	substring = ft_calloc(len + 1, sizeof(char));
// 	if (substring == NULL)
// 		return (NULL);
// 	ft_strlcpy(substring, s, len + 1);
// 	return (substring);
// }
