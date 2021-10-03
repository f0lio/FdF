
#include "fdf.h"

static	char			*join_chr(char const *line, char c, size_t len)
{
	char		*s;
	size_t		i;

	if (!(s = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
		s[i++] = (*line) ? *line++ : c;
	s[i] = '\0';
	return (s);
}

int						read_line(int fd, char **line)
{
	int			ret;
	int			len;
	char		buf;
	char		*tmp;

	if (!line || !(*line = (char *)malloc(1)))
		return (-1);
	**line = '\0';
	len = 0;
	while ((ret = read(fd, &buf, 1)) > 0 && buf != '\n')
	{
		if (!(tmp = join_chr(*line, buf, ++len)))
			return (-1);
		free(*line);
		*line = tmp;
	}
	if (ret == -1)
		return (-1);
	return (len);
}
