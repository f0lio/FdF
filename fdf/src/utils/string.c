
#include "fdf.h"

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
	return s;
}
