/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarment <msarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:38:49 by msarment          #+#    #+#             */
/*   Updated: 2023/09/12 18:00:43 by msarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <unistd.h>
# include <stdlib.h>

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s, int type);

#endif