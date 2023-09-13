#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	len = ft_strlen (s1, 1) + ft_strlen (s2, 1);
	str = (char *) malloc (sizeof (char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s, int type)
{
	size_t	i;

	i = 0;
	if(type == 2 || type == 3)
	{
		if (s)
		{
			while (s[i] != '\0')
			{
				if (s[i] == '\n')
					return (i + 1);
				i++;
			}
			if (type == 3 && s[i] == '\0')
				return (i + 1);
		}
		return (0);
	}
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	strlen;
	size_t	size;
	size_t	i;

	strlen = ft_strlen(s, 1);
	if (start >= strlen)
		size = 0;
	else if (len >= strlen)
		size = (strlen - start);
	else if (strlen - start <= len)
		size = (strlen - start);
	else
		size = len;
	sub = malloc(size + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (((i + start) < strlen) && (i < len))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*mem;
	unsigned int	full_size;
	unsigned long	i;

	full_size = count * size;
	if (size == 0 || count == 0)
		return (malloc(0));
	if ((full_size > __INT_MAX__) || (full_size / count != size))
		return (NULL);
	mem = malloc (full_size);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < full_size)
	{
		*(unsigned char *)(mem + i) = '\0';
		i++;
	}
	return (mem);
}