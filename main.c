#include "get_next_line.h"

/* int	main(void)
{
	char *str1;
	char *str2;
	char *str3;
	int fd1;
	int fd2;
	int fd3;
	int	i;

	i = 0;
	fd1 = open("teste1", O_RDONLY);
	fd2 = open("teste2", O_RDONLY);
	fd3 = open("teste3", O_RDONLY);
	while(i < 3)
	{
		str1 = get_next_line(fd1);
		str2 = get_next_line(fd2);
		str3 = get_next_line(fd3);
		printf("%s%s%s\n", str1, str2, str3);
		free(str1);
		free(str2);
		free(str3);
		i++;
	}

	close (fd1);
	close (fd2);
	close (fd3);
}
 */
int	main(void)
{
	int fd = open("teste", O_RDONLY);
	int i = 0;
	char *str;
	while(i < 2)
	{
		str = get_next_line(fd);
		printf("%s",str);
		free(str);
		i++;
	}
	printf("\n");
	if (BUFFER_SIZE > 100) {
		char *temp;
		do {
			temp = get_next_line(fd);
			free(temp);
		} while (temp != NULL);
	}
	close(fd);
	fd = open("teste", O_RDONLY);
	i = 0;
	while(i < 4)
	{
		str = get_next_line(fd);
		printf("%s",str);
		free(str);
		i++;
	}
	close(fd);
}