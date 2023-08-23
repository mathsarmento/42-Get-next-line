/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarment <msarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:40:50 by msarment          #+#    #+#             */
/*   Updated: 2023/08/23 19:57:50 by msarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*copyread(char *line, char **save);
static char *readfile(char **line, char **save, int fd);
static char	*savecpy(char **save);

char	*get_next_line(int fd)
{
	static char	*save; // salvar a string 
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = savecpy(&save);
	if(line)
	{
		if(line[ft_strlen(line) - 1] == '\n')
			return (line);
	}
	line = readfile(&line, &save, fd);
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
		*line = ft_substr(aux_line, 0, ft_strlen(aux_line));
		if (line[0][ft_strlen(*line) - 1] == '\n')
			break;
		// printf("\nFREE NO SAVE\n\n");
		// free(*save);
		// *save = ft_calloc(BUFFER_SIZE + 1, 1);
		free(aux_line);
		num = read(fd, *save, BUFFER_SIZE);
	}
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
	size_t	i;
	char	*line;

	line = NULL;
	i = 0;

	if (*save)
	{
		while (**save != '\n' && **save)
			*save += 1;
		*save += 1;
		if (!**save)
			return (NULL);
		while (save[0][i] != '\n' && save[0][i])
			i++;
		line = ft_substr(*save, 0, i + 1);
	}
	return(line);
}

int	main(void)
{
	char *str;
	char *str2;
	char *str3;

	int fd;

	fd = open("teste", O_RDONLY);
	str = get_next_line(fd);
	str2 = get_next_line(fd);
	str3 = get_next_line(fd);
	printf("\n\nFIRST LINE => %s", str);
	printf("2 LINE => %s", str2);
	printf("3 LINE => %s\n", str3);
	close (fd);
}

// void readfile(char *str, char *save, int fd)
// {
// 	size_t numRead;
// 	size_t	*sumloc;
// 	char	*readSave;

// 	while (sumloc < __INT_MAX__)
// 	{
// 		readSave = malloc(BUFFER_SIZE);
// 		numRead = read(fd, readSave, BUFFER_SIZE);
// 		if (numRead != BUFFER_SIZE)
// 			//CHEGOU NO FINAL DO READ
// 		if (checkread(readSave, &sumloc))
// 		{

// 		}
// 		free(readSave);
		


// 	}
// }

// int	checkread(char *readSave, size_t *sumloc)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < BUFFER_SIZE)
// 	{
// 		if (reaSave[i] == '\n')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

