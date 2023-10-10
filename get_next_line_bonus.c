/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:12:25 by kryrodri          #+#    #+#             */
/*   Updated: 2023/10/10 17:35:13 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_clean(char **s1, char **s2)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (NULL);
}

char	*read_fd(int fd, char *reading)
{
	char	*aux_reading;
	int		q_chars;

	q_chars = 1;
	aux_reading = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!aux_reading)
		return (ft_clean(&reading, &reading));
	while (!ft_strchr(reading, '\n') && q_chars != 0)
	{
		q_chars = read(fd, aux_reading, BUFFER_SIZE);
		if (q_chars < 0)
			return (ft_clean(&reading, &aux_reading));
		if (q_chars > 0)
		{
			aux_reading[q_chars] = '\0';
			reading = ft_strjoin(reading, aux_reading);
			if (!reading)
				return (NULL);
		}
	}
	if (aux_reading)
		free(aux_reading);
	return (reading);
}

char	*save_line(char *reading)
{
	int		i;
	char	*line;

	i = 0;
	if (!reading[i])
		return (NULL);
	while (reading[i] && reading[i] != '\n')
		i++;
	if (reading[i] == '\n')
		i++;
	line = (char *)ft_calloc((i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (reading[i] && reading[i] != '\n')
	{
		line[i] = reading[i];
		i++;
	}
	if (reading[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*save_reading(char *reading)
{
	int		i;
	int		j;
	char	*new_reading;

	i = 0;
	j = 0;
	while (reading && reading[i] && reading[i] != '\n')
		i++;
	if (reading && !reading[i])
		return (ft_clean(&reading, NULL));
	new_reading = (char *)ft_calloc((ft_strlen(reading) - i + 1), sizeof(char));
	if (!new_reading)
		return (ft_clean(&reading, NULL));
	i++;
	while (reading[i] != '\0')
		new_reading[j++] = reading[i++];
	new_reading[j] = '\0';
	ft_clean(&reading, NULL);
	reading = NULL;
	return (new_reading);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*reading[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reading[fd] = read_fd(fd, reading[fd]);
	if (!reading[fd])
		return (NULL);
	line = save_line(reading[fd]);
	if (!line)
	{
		free(reading[fd]);
		reading[fd] = NULL;
	}
	else
		reading[fd] = save_reading(reading[fd]);
	return (line);
}
