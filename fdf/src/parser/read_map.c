
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
    t_file  *file;
    t_node  *it;
    char    *line;
    int     i;
    int     len;

    file = &env->file;
    file->map = (char**) malloc((file->lines_count + 1) * sizeof(char*));
    it = file->lines;
    i = 0;
    while (it)
    {
        line = it->data;
        len = str_len(line);
        file->map[i] = line; //pro-tech-shen?
        it = it->next;
        i++;
    }
}