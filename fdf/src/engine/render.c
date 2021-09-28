
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
	if (key == KEY_ESC)
        close_window(env);
    controllers(env, key);
    clear_window(env);
    render(env);    
    return 0;
}

static void    render(t_env *env)
{
    int     x;
    int     y;

    y = 0;
    while (y < env->matrix.rows)
    {
        x = 0;
        while (x < env->matrix.cols)
        {
            if (x < env->matrix.cols - 1)
                project_line(env, x, y, x + 1, y);
            if (y < env->matrix.rows - 1)
                project_line(env, x, y, x, y + 1);   
            x++;
        }
        y++;
    }
    update_window(env);
}
