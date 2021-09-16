
#include "fdf.h"

void    init_env(t_env *env, int argc, const char **argv)
{
    env->argc = argc;
    env->argv = argv;
    env->map_fd = -1;
    env->map = NULL;
}

void    setup(t_env *env)
{
    open_map(env);
    read_map(env);
    // parse_map(env);
}



int		main(int argc, const char **argv)
{
	t_env	env;

    init_env(&env, argc, argv);
    setup(&env);
    // render(env);
	return (0);
}
