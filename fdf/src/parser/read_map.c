
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
    t_file  *file;

    file = &env->file;
    while (read_line(file->fd, &line) > 0 && ++file->lines_count)
        push_back(&file->lines, line);
}

void    parse_map(t_env *env)
{
    t_file  *file;
    t_node  *it;
    char    *line;
    int     i;
    int     len;

    file = &env->file;
    it = file->lines;
    file->map = malloc(file->lines_count + 1);
    file->map[file->lines_count] = NULL;
    i = 0;
    while (i < file->lines_count)
    {
        line = it->data;
        len = str_len(line);
        file->map[i] = malloc(len + 1); //pro-tech-shen?
        file->map[i][len] = 0;
        it = it->next;
        i++;
    }
}