
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