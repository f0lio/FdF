
#include "fdf.h"

static void    setup(t_env *env)
{
    if (env->argc != 2)
        error_exit(env, ERR_ARG);
    open_map(env);
    read_map(env);
    parse_map(env);
    env->horizontal_shift = env->win.width / 3;
    env->vertical_shift = env->win.height / 3;
    //check map validity
}

int		main(int argc, const char **argv)
{
	t_env	env;

    init_env(&env, argc, argv);
    setup(&env);
    start_engine(&env);
	return (0);
}
