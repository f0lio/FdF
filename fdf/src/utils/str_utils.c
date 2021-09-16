
#include "fdf.h"

size_t	str_len(const char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\n')
		len++;
	return (len);
}
