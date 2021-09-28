
# include "fdf.h"

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
    t_file  *file;
    
    file = &env->file;
    while (read_line(file->fd, &line) > 0)
    {
        push_back(&file->lines, str_dup(line));
        free(line);
        file->lines_count++;
    }
}

void    parse_map(t_env *env)
{
    t_matrix    *matrix;
    t_node      *it;
    int         i;

    matrix = &env->matrix;
    matrix->rows = env->file.lines_count;
    matrix->data = (int**) malloc((matrix->rows + 1) * sizeof(int*));
    it = env->file.lines;
    i = 0;
    
    while (it)
    {
        matrix->data[i] = parse_map_line(it->data, i, &matrix->cols);
        it = it->next;
        i++;
    }    
}

int    *parse_map_line(char *line, int row, int *cols)
{
    int     *points;
    int     i;
    int     col;
    int     len;

    len = 0;
    col = 1;
    while (line[len])
        col += line[len++] == ' ';
    points = (int*)malloc(col * sizeof(int));
    i = 0;
    col = 0;
    while (i < len)
    {
        points[col] = str_to_int(&line[i]);
        i += nbr_len(points[col]) + 1;    
        col++;
        // printf("$$%d\n", col);
    }
    // printf("##################\n##################\n##################\n");
    *cols = col;
    return points;
}
