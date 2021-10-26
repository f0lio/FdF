
// #include "fdf.h"

// int			has_return(char *str)
// {
// 	int i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i])
// 	{
// 		if (str[i] == '\n')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// char	*get_save(char *save)
// {
// 	char	*rtn;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	if (!save)
// 		return (0);
// 	while (save[i] && save[i] != '\n')
// 		i++;
// 	if (!save[i])
// 	{
// 		free(save);
// 		return (0);
// 	}
// 	if (!(rtn = malloc(sizeof(char) * ((str_len(save) - i) + 1))))
// 		return (0);
// 	i++;
// 	while (save[i])
// 		rtn[j++] = save[i++];
// 	rtn[j] = '\0';
// 	free(save);
// 	return (rtn);
// }

// char	*_get_line(char *str, int *len)
// {
// 	int		i;
// 	char	*rtn;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i] && str[i] != '\n')
// 		i++;
// 	if (!(rtn = malloc(sizeof(char) * (i + 1))))
// 		return (0);
// 	i = 0;
// 	while (str[i] && str[i] != '\n')
// 	{
// 		rtn[i] = str[i];
// 		i++;
// 	}
// 	rtn[i] = '\0';
// 	*len = i;
// 	return (rtn);
// }

// int		read_line(int fd, char **line)
// {
// 	char			*buff;
// 	static char		*save;
// 	int				reader;
// 	int				len;

// 	reader = 1;
// 	if (fd < 0 || !line || BUFFER_SIZE <= 0)
// 		return (-1);
// 	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
// 		return (-1);
// 	while (!has_return(save) && reader != 0)
// 	{
// 		if ((reader = read(fd, buff, BUFFER_SIZE)) == -1)
// 		{
// 			free(buff);
// 			return (-1);
// 		}
// 		buff[reader] = '\0';
// 		save = str_join(save, buff);
// 	}
// 	free(buff);
// 	*line = _get_line(save, &len);
// 	save = get_save(save);
// 	if (reader == 0)
// 		return (0);
// 	return (len);
// }
