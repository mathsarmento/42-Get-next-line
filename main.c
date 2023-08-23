#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// void	changestr(char *str)
// {
// 	free(str);
// 	str = malloc(10);
// 	str[0] = 'p';
// 	str[1] = 'e';
// 	str[2] = 'd';
// 	str[3] = 'r';
// 	str[4] = 'o';
// 	str[5] = '\0';
// }

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	len = ft_strlen (s1) + ft_strlen (s2);
	str = (char *) malloc (sizeof (char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && s2[j] != '\n')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char *junta(char *str, char *str2)
{
	char *cpy;

	cpy = ft_strjoin(str, str2);
	return (cpy);
}

int	main(void)
{
	char *str;
	int  i = 0;

	while (i  == 0)
	{
		str = malloc(20);
		i = ft_strlen (str);
		printf ("%s\n", str);
		free (str);
	}
	

}