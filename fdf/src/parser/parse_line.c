
#include "fdf.h"

t_point *parse_map_line(t_env *env, t_string *line, int *cols)
{
	char		**pts;
	char		**items;
	t_point		*points;
	int			i;
	int			col;

	pts = str_split(line->buf, ' ', &col);
	if (!pts)
		error_exit(env, ERR_INV_MAP);
	points = (t_point*)malloc((col + 1) * sizeof(t_point));
	if (!points)
	{
		free_splited_items(pts, col);
		error_exit(env, ERR_MALLOC);
	}
	i = 0;
	while (i < col)
	{
		reset_point(&points[i]);
		items = str_split(pts[i], ',', NULL);
		if (!items)
			error_exit(env, ERR_INV_MAP);
		points[i].z = str_to_int(items[0]);
		if (items[1])
			points[i].color = str_hex_to_int(items[1]);
		else
		{
			if (points[i].z)
				points[i].color = KINDA_COOL_COLOR;
			else
				points[i].color = DEFAULT_COLOR;
		}
		free_splited_items(items, (items[0] && items[1]) + 1);
		if (points[i].z > env->max_z)
			env->max_z = points[i].z;
		i++;
	}
	free_splited_items(pts, col);
	*cols = col;
	return points;
}

void		free_splited_items(char **items, int size)
{
	if (!items)
		return ;
	while (--size > -1)
	{
		free(items[size]);
		items[size] = NULL;
	}
	free(items);
	items = NULL;
}