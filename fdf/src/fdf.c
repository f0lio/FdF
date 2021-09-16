
#include "fdf.h"

void    init_file(t_file *file)
{
    file->fd = -1;
    file->lines = NULL;
    file->lines_count = 0;
    file->map = NULL;
}

void    init_env(t_env *env, int argc, const char **argv)
{
    env->argc = argc;
    env->argv = argv;
    init_file(&env->file);
}

void    setup(t_env *env)
{
    if (env->argc != 2)
        error_exit(env, ERR_ARG);
    open_map(env);
    read_map(env);
    parse_map(env);
}

int		main(int argc, const char **argv)
{
	t_env	env;

    init_env(&env, argc, argv);
    setup(&env);
    // render(env);
	return (0);
}
