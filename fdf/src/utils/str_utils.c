#include "fdf.h"

size_t	str_len(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*str_dup(const char *str)
{
	char			*dup;
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	dup = (char *)malloc(i + 1);
	if (!dup)
		return (0);
	dup[i] = '\0';
	while (i--)
		dup[i] = str[i];
	return (dup);
}

int	count_by_delim(char *str, char c)
{
	int	count;
	int	i;

	if (!str)
		return (-1);
	count = 0;
	i = skip_char(str, ' ');
	while (str[i])
	{
		if (str[i] == c)
		{
			count++;
			while (str[i] && str[i] == c)
				i++;
			if (str[i] == '\0')
				break ;
		}
		i++;
	}
	return (count + 1);
}

char	*sub_str(char *line, unsigned start, unsigned end)
{
	char	*sub;

	sub = malloc(end - start + 1);
	if (!sub)
		return (NULL);
	while (start < end)
	{
		*sub = line[start];
		start++;
		sub++;
	}
	*sub = 0;
	return (sub);
}

void	*mem_alloc(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	while (--size > -1)
		((char *)ptr)[size] = 0;
	return (ptr);
}
