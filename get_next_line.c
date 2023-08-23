/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarment <msarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:40:50 by msarment          #+#    #+#             */
/*   Updated: 2023/08/20 17:48:04 by msarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*copyread(char *line, char *save);
static char *readfile(char *line, char *save, int fd);

char	*get_next_line(int fd)
{
	static char	*save; // salvar a string 
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > __INT_MAX__)
		return (NULL);
	printf("ENTROU NA FUNÇÃO GNL\n");
	line = readfile(line, save, fd);
	printf("SAIU DA FUNC READ LINE\n");
	return (line);
}

static char *readfile(char *line, char *save, int fd)
{
	size_t	num;
	size_t	i;
	char	*aux_line;

	i = 0;
	line = NULL;
	if (save)
	{
		while (save[i] == '\n' || save[i])
		i++;
		if (!save[i])
			return (NULL);
		line = ft_substr(save, i + 1, BUFFER_SIZE - i - 1);
		free(save);
	}
	save = ft_calloc(BUFFER_SIZE + 1, 1);
	num = read(fd, save, BUFFER_SIZE);
	while (num)
	{
		if(!line)
			line = ft_calloc(1, 1);
		printf("ENTROU NO WHILE\n");
		aux_line = copyread(line, save);
		free(line);
		line = ft_substr(aux_line, 0, ft_strlen(aux_line));
		if (line[ft_strlen(line) - 1] != '\n')
			break;
		free(save);
		free(aux_line);
		num = read(fd, save, BUFFER_SIZE);
	}
	printf("NÃO ENTROU NO WHILE\n");
	return (line);
}

static char	*copyread(char *line, char *save)
{
	char	*cpy;
	char	*aux_cpy;
	size_t	findbackspace;

	printf("ENTROU NA FUNÇÃO copyread\n");
	findbackspace = 0;
	while(save[findbackspace] != '\n')
	{
		if(!save[findbackspace])
		{
			cpy = ft_strjoin(line, save);
			return (cpy);
		}
		findbackspace++;
	}
	printf("ACHOU O \\n \n");
	aux_cpy = ft_substr(save, 0, findbackspace + 1);
	printf("AUX CPY => %s", aux_cpy);
	cpy = ft_strjoin(line, aux_cpy);
	printf("CPY => %s", cpy);
	free (aux_cpy);
	return (cpy);
}

int	main(void)
{
	char *str;
	char *str2;
	int fd;

	fd = open("teste", O_RDONLY);
	str = get_next_line(fd);
	str2 = get_next_line(fd);
	printf("\n\nFIRST LINE => %s\n\n", str);
	printf("2 LINE => %s\n\n", str2);
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
// 		if (readSave[i] == '\n')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

