#include "fdf.h"

void	open_map(t_env *env)
{
	env->file.fd = open(env->argv[1], O_RDONLY);
	if (env->file.fd < 0)
		error_exit(env, ERR_OPEN);
}

void	read_map(t_env *env)
{
	char	*line;
	int		len;
	t_file	*file;

	open_map(env);
	file = &env->file;
	while (1)
	{
		if (read_line(file->fd, &line) < 1)
		{
			safe_free((void **)&line);
			break ;
		}
		len = str_len(line);
		if (len < 1)
			break ;
		push_back(&file->lines,
			make_string(line, len));
		safe_free((void **)&line);
		file->lines_count++;
	}
	close(env->file.fd);
}

void	parse_map(t_env *env)
{
	t_matrix	*matrix;
	t_node		*it;
	int			i;
	int			tmp;

	matrix = &env->matrix;
	matrix->rows = env->file.lines_count;
	matrix->data = (t_point **)malloc(
			matrix->rows * sizeof(t_point*));
	if (!matrix->data)
		error_exit(env, ERR_MALLOC);
	it = env->file.lines;
	i = 0;
	while (it)
	{
		matrix->data[i] = parse_map_line(
				env, it->data, &matrix->cols);
		if (!matrix->data[i] || (i && tmp != matrix->cols))
			error_exit(env, ERR_INV_MAP);
		else
			tmp = matrix->cols;
		it = it->next;
		i++;
	}
}
