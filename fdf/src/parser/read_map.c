
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
    int     len;
    t_file  *file;

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
}
