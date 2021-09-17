
#include "fdf.h"

static void    setup(t_env *env)
{
    if (env->argc != 2)
        error_exit(env, ERR_ARG);
    open_map(env);
    read_map(env);
    parse_map(env);
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
