
#include "fdf.h"

void    start_engine(t_env *env)
{
    set_window(env);
    render(env);
    mlx_hook(env->win.win_p, 2, 1L << 0, update, env);
	mlx_hook(env->win.win_p, EXIT_BTN, 1L << 0, close_window, env);
	mlx_loop(env->win.mlx_p);
}

static int    update(int key, t_env *env)
{
	if (key == ESC_KEY)
        close_window(env);
    render(env);
    return 0;
}
