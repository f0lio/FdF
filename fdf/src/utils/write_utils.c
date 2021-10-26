#include "fdf.h"

void	put_char(char c)
{
	write(1, &c, 1);
}

void	put_str(char *str)
{
	write(1, str, str_len(str));
}
