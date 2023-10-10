/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:12:34 by kryrodri          #+#    #+#             */
/*   Updated: 2023/10/10 17:48:29 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	char	*copia;
	size_t	i;
	size_t	j;

	j = num_elements * element_size;
	copia = malloc(j);
	if (!copia)
		return (NULL);
	i = 0;
	while (i < j)
	{
		((char *)copia)[i] = '\0';
		i++;
	}
	return (copia);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_string;
	int		i;
	int		j;

	j = ft_strlen(s1) + ft_strlen(s2);
	new_string = (char *)ft_calloc((j + 1), sizeof(char));
	if (!new_string)
	{
		return (ft_clean(&s1, &s2));
	}
	i = 0;
	while (s1 && s1[i])
	{
		new_string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		new_string[i++] = s2[j++];
	}
	new_string[i] = '\0';
	free(s1);
	return (new_string);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c > 256)
		c %= 256;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		++i;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}
