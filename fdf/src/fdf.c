
#include "fdf.h"

static void    setup(t_env *env)
{
    if (env->argc != 2)
        error_exit(env, ERR_ARG);
    env->horizontal_shift = env->win.width / 3;
    env->vertical_shift = env->win.height / 3;
    read_map(env);
    parse_map(env);
}

static void    start_engine(t_env *env)
{
    set_window(env);
    set_event_hooks(env);	
    render(env);
    mlx_loop(env->win.mlx_p);
}

void    update(t_env *env)
{
    clear_window(env);
    render(env);
}
int		main(int argc, const char **argv)
{
	t_env	env;

    init_env(&env, argc, argv);
    setup(&env);
    start_engine(&env);
	return (0);
}
