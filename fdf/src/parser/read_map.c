
# include "fdf.h"

void    open_map(t_env *env)
{
    env->map_fd = open(env->argv[1], O_RDONLY);
    if (env->map_fd < 0)
        error_exit(env, ERR_OPEN);
}

void    read_map(t_env *env)
{
    char *line;

    while (read_line(env->map_fd, &line) > 0)
    {
        printf("[%s]\n", line);
    }

}
