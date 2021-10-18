
#include "fdf.h"

void    open_map(t_env *env)
{
    env->file.fd = open(env->argv[1], O_RDONLY);
    if (env->file.fd < 0)
        error_exit(env, ERR_OPEN);
}

void    read_map(t_env *env)
{
    char    *line;
    char    *map;
    int     len;
    t_file  *file;
    
    open_map(env);
    file = &env->file;
    while (1)
    {
        len = read_line(file->fd, &line);
        if (len < 1)
            break ;
        push_back(&file->lines, make_string(line, len));
        free(line);
        file->lines_count++;
    }
    close(env->file.fd);
}

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
        free(((t_string*)it->data)->buf);
        free(it->data);
		it = it->next;
		i++;
	}
}
