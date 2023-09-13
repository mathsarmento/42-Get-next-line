/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarment <msarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:40:50 by msarment          #+#    #+#             */
/*   Updated: 2023/09/12 20:59:54 by msarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*copyread(char *line, char **save);
static char *readfile(char **line, char **save, int fd);
static char	*savecpy(char **save);

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		if (save)
		{
			free(save);
			save = NULL;
		}
		return (NULL);
	}
	line = savecpy(&save);
	if (ft_strlen(line, 2))
		return (line);
	line = readfile(&line, &save, fd);
	if (line)
	{
		if(line[0] == '\0')
		{
			free(line);
			return(NULL);
		}
	}
	return (line);
}

static char *readfile(char **line, char **save, int fd)
{
	size_t	num;
	char	*aux_line;

	*save = ft_calloc(BUFFER_SIZE + 1, 1);
	num = read(fd, *save, BUFFER_SIZE);
	while (num)
	{
		save[0][num] = '\0';
		if(!*line)
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

static char	*copyread(char *line, char **save)
{
	char	*cpy;
	char	*aux_cpy;
	size_t	findbackspace;

	findbackspace = 0;
	while(save[0][findbackspace] != '\n')
	{
		if(!save[0][findbackspace])
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

static char	*savecpy(char **save)
{
	char	*line;
	char	*aux_save;
	// O SAVE JA VEM COM UM \N QUE JA FOI COPIADO
	//existem duas situações -> ou o save tem \0 (significa que acabou o save)
	// ou -> tem \n e ainda tem mais coisa no save
	line = NULL;
	if (ft_strlen(*save, 3)) // aqui não entra se não ter save
	{
		aux_save = ft_substr(*save, ft_strlen(*save, 2), ft_strlen(*save, 1));
		free (*save);
		if(ft_strlen(aux_save, 1) == ft_strlen(aux_save, 3) - 1) // final save
		{
			line = ft_substr(aux_save, 0, ft_strlen(aux_save, 1));
			*save = NULL;
		}
		else if (ft_strlen(aux_save, 1) > ft_strlen(aux_save, 3) - 1) // existe um \n
		{
			line = ft_substr(aux_save, 0, ft_strlen(aux_save, 3));
			*save = ft_substr(aux_save, 0, ft_strlen(aux_save, 1));
		}
		free(aux_save);
	}
	return(line);
}


	// if (*save)
	// {
	// 	aux_save = ft_substr(*save, 0, ft_strlen(*save, 1));
	// 	free(*save);
	// 	*save = NULL;
	// 	while (aux_save[cont] != '\n' && aux_save[cont])
	// 		cont++;
	// 	if (!aux_save[cont])
	// 	{
	// 		free(aux_save);
	// 		return (NULL);
	// 	}
	// 	cont++;
	// 	while (aux_save[i + cont] != '\n' && aux_save[i + cont])
	// 		i++;
	// 	line = ft_substr(aux_save, cont, i + 1);
	// 	if (aux_save[i + cont] == '\n')
	// 		*save = ft_substr(aux_save, i + cont, ft_strlen(aux_save, 1) - i - cont);
	// 	free(aux_save);
	// }