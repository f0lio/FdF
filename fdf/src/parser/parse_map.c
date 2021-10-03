
#include "fdf.h"

void    parse_map(t_env *env)
{
	t_matrix    *matrix;
	t_node      *it;
	int         i;
	t_point     p;

	matrix = &env->matrix;
	matrix->rows = env->file.lines_count;
	matrix->data = (t_point**)malloc(
				(matrix->rows + 1) * sizeof(t_point*));
	it = env->file.lines;
	i = 0;
	while (it)
	{
		matrix->data[i] = parse_map_line(
								it->data, &matrix->cols);
		it = it->next;
		i++;
	}
}

t_point    *parse_map_line(t_string *line, int *cols)
{
	t_point     *points;
	char        *hex;
	int         i;
	int         col;

	col = count_by_delim(line->buf, ' ');
	points = (t_point*)malloc(col * sizeof(t_point));
	i = 0;
	col = 0;
	while (i < line->len)
	{
		points[col].z = str_to_int(&line->buf[i]);
		i += nbr_len(points[col].z);

		// printf("#[%s]\n", &line->buf[i]);
		// printf("#p[%d]\n", (int)points[col].z);

		if (i >= line->len)
			break ;

		hex = get_hex_from_line(&line->buf[i]);
		if (hex) // && hex[0] != '\0')
		{
			// printf("x:[%s]\n", hex);
			points[col].color = str_hex_to_int(hex);
			points[col].color = 0x00ff00;
			i += str_len(hex) + 1;
			free(hex);
		}
		else
		{
			if (points[col].z)
				points[col].color = points[col].z * 0xef0000;
			else
				points[col].color = DEFAULT_COLOR;
			i++;
		}
		col++;
	}
	*cols = col;
	return points;
}

char *get_hex_from_line(char *line)
{
	char    *hex;
	int     i;
	int     j;
	int     len;
	BOOL	flag;

	i = 0;
	flag = 0;
	while (line[i])
	{
		if (line[i] == ',')
		{
			i++;
			flag = TRUE;
			break ;
		}
		i++;
	}
	if (!flag)
	{
		return NULL;
	}
	j = i;
	len = 0;
	while (line[i] && line[i] != ' ')
	{
		i++;
		len++;
	}
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
