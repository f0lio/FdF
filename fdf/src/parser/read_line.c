
#include "fdf.h"

static	char			*join_chr(char const *line, char c, size_t len)
{
	char		*s;
	size_t		i;

	s = (char*)malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	len--;
	while (i < len)
	{
		s[i] = line[i];
		i++;
	}
	s[i] = c;
	s[i + 1] = '\0';
	return (s);
}

int						read_line(int fd, char **line)
{
	int			ret;
	int			len;
	char		buf;
	char		*tmp;

	if (!line)
		return (-1);
	*line = (char *)malloc(1);
	if (*line == NULL)
		return (-1);
	**line = '\0';
	len = 0;
	while ((ret = read(fd, &buf, 1)) > 0 && buf != '\n')
	{
		tmp = *line;
		*line = join_chr(*line, buf, ++len);
		if (!tmp)
			return (-1);
		free(tmp);
		
	}
	if (ret == -1)
		return (-1);
	return (len);
}
