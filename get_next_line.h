/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryrodri <kryrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:45:46 by kryrodri          #+#    #+#             */
/*   Updated: 2023/10/01 15:29:13 by kryrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5

#  endif

# include <stdio.h> // NULL
# include <stdlib.h> // malloc y free
# include <unistd.h> // write, close
#include <limits.h>

char	*get_next_line(int fd);
int	ft_look_for_line(char *s);
int	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
void	ft_clean(char **brut);

#endif




