
#include "fdf.h"

size_t	str_len(const char *str)
{
	size_t len;

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

int count_by_delim(char *str, char c)
{
	int count;

	if (!str)
		return -1;
	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		*str++;
	}
	return count + 1;
}

t_string *init_string(int size)
{
	t_string *s;

	s = (t_string*)malloc(sizeof(t_string));
	s->buf = (char*)malloc(size + 1);
	s->buf[size] = 0;
	s->len = size;
	return s;
}

t_string *make_string(char *buf, int len)
{
	t_string *s;


	if (!buf)
		return NULL;
	if (len == -1)
		len = str_len(buf);
	s = init_string(len);
	len--;
	while (len > -1)
	{
		s->buf[len] = buf[len];
		len--;
	}
	// printf("->[%s]\n", s->buf);
	return s;
}
