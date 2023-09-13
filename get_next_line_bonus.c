/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarment <msarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:11:01 by msarment          #+#    #+#             */
/*   Updated: 2023/09/13 16:11:32 by msarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*save[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		if (save[fd])
		{
			free(save[fd]);
			save[fd] = NULL;
		}
		return (NULL);
	}
	line = savecpy(&save[fd]);
	if (ft_strlen(line, 2))
		return (line);
	line = readfile(&line, &save[fd], fd);
	if (line)
	{
		if (line[0] == '\0')
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

char	*readfile(char **line, char **save, int fd)
{
	size_t	num;
	char	*aux_line;

	*save = ft_calloc(BUFFER_SIZE + 1, 1);
	num = read(fd, *save, BUFFER_SIZE);
	while (num)
	{
		save[0][num] = '\0';
		if (!*line)
			*line = ft_calloc(1, 1);
		aux_line = copyread(*line, save);
		free(*line);
		*line = ft_substr(aux_line, 0, ft_strlen(aux_line, 1));
		free(aux_line);
		if (line[0][ft_strlen(*line, 1) - 1] == '\n')
			return (*line);
		num = read(fd, *save, BUFFER_SIZE);
	}
	free(*save);
	*save = NULL;
	return (*line);
}

char	*copyread(char *line, char **save)
{
	char	*cpy;
	char	*aux_cpy;
	size_t	findbackspace;

	findbackspace = 0;
	while (save[0][findbackspace] != '\n')
	{
		if (!save[0][findbackspace])
		{
			cpy = ft_strjoin(line, *save);
			return (cpy);
		}
		findbackspace++;
	}
	aux_cpy = ft_substr(*save, 0, findbackspace + 1);
	save += findbackspace + 1;
	cpy = ft_strjoin(line, aux_cpy);
	free (aux_cpy);
	return (cpy);
}

char	*savecpy(char **save)
{
	char	*line;
	char	*aux_save;

	line = NULL;
	if (ft_strlen(*save, 3))
	{
		aux_save = ft_substr(*save, ft_strlen(*save, 2), ft_strlen(*save, 1));
		free (*save);
		if (ft_strlen(aux_save, 1) == ft_strlen(aux_save, 3) - 1)
		{
			line = ft_substr(aux_save, 0, ft_strlen(aux_save, 1));
			*save = NULL;
		}
		else if (ft_strlen(aux_save, 1) > ft_strlen(aux_save, 3) - 1)
		{
			line = ft_substr(aux_save, 0, ft_strlen(aux_save, 3));
			*save = ft_substr(aux_save, 0, ft_strlen(aux_save, 1));
		}
		free(aux_save);
	}
	return (line);
}
