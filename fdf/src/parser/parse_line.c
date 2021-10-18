
#include "fdf.h"

t_point	*parse_map_line(t_string *line, int *cols)
{
	t_point		*points;
	int			i;
	int 		c;
	int			col;
	char		*hex;

	col = count_by_delim(line->buf, ' ');
	points = (t_point*)malloc(col * sizeof(t_point));
	i = 0;
	c = 0;
	while (i < line->len && c < col)
	{
		points[c].z = str_to_int(&line->buf[i]);
		
		i += nbr_len(points[c].z);
		if (i >= line->len)
			break ;
		hex = get_hex_from_line(&line->buf[i]);
		if (hex)
		{	
			points[c].color = str_hex_to_int(hex);
			points[c].color = 0x00ff00;
			i += str_len(hex) + 1;
			free(hex);
		}
		else
		{
			if (points[c].z)
				points[c].color = points[c].z * 0xef0000;
			else
				points[c].color = DEFAULT_COLOR;
			i++;
		}
		c++;
	}
	*cols = col;
	return points;
}

int parse_color(char *buf, int *i)
{
	int		color;
	char	*hex;	

	hex = get_hex_from_line(&buf[*i]); //7 
	printf("i: %d\n", *i);
	printf("[%s]\n", &buf[*i]);
	if (hex)
	{
		color = str_hex_to_int(hex);
		*i += str_len(hex) + 1;
		free(hex);
		return color;
	}
	*i++;
	return DEFAULT_COLOR;
}

char *get_hex_from_line(char *line)
{
	char	*hex;
	int		i;
	int		j;
	int		len;

	i = has_color(line);
	if (i < 0)
		return NULL;
	j = i;
	len = 0;
	while (line[i] && line[i] != ' ' && line[i] != '\t')
	{
		i++;
		len++;
	}
	// hex = sub_str(line, j, len);
	hex = (char*)malloc(len + 1);
	hex[len] = 0;
	i = 0;
	while (i < len)
	{
		hex[i] = line[j];
		j++;
		i++;
	}
	return hex;
}

int has_color(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			return i;
		if (line[i] != ' ')
			break ;
		i++;
	}
	return -1;
}
