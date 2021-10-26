#include "fdf.h"

t_point	*parse_map_line(t_env *env, t_string *line, int *col)
{
	t_point		*points;
	char		**pts;
	char		**items;
	int			i;

	pts = str_split_wrapper(env, line->buf, ' ', col);
	points = (t_point *)malloc((*col + 1) * sizeof(t_point));
	if (!points)
	{
		free_splited_items(pts, *col);
		error_exit(env, ERR_MALLOC);
	}
	i = 0;
	while (i < *col)
	{
		items = str_split_wrapper(env, pts[i], ',', NULL);
		points[i].z = str_to_int(items[0]);
		parse_color(items, &points[i]);
		if (points[i].z > env->max_z)
			env->max_z = points[i].z;
		i++;
	}
	free_splited_items(pts, *col);
	return (points);
}

void	parse_color(char **items, t_point *p)
{
	if (items[1])
		p->color = str_hex_to_int(items[1]);
	else
	{
		if (p->z)
			p->color = KINDA_COOL_COLOR;
		else
			p->color = DEFAULT_COLOR;
	}
	free_splited_items(items, (items[0] && items[1]) + 1);
}
