
#include "fdf.h"

static void    setup(t_env *env)
{
    if (env->argc != 2)
        error_exit(env, ERR_ARG);
    open_map(env);
    read_map(env);
    parse_map(env);
    set_window(env);
}

static void    render(t_env *env)
{
    int i, j;
    t_point p;
    t_win *win;
    
    win = &env->win;

    p.color = 0xffffff;
    i = 20;
    while (i < 100)
    {
        j = 20;
        p.x = i;
        while (j < 100)
        {
            p.y = j;
			pxl(env, &p);
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(win->mlx_p, win->win_p, win->img_p, 0, 0);
}

static int    update(int key, t_env *env)
{
    printf("key: %d\n", key);

	if (key == ESC_KEY)
        close_window(env);
    return 0;
}

int		main(int argc, const char **argv)
{
	t_env	env;

    init_env(&env, argc, argv);
    setup(&env);
    render(&env);

    mlx_hook(env.win.win_p, 2, 1L << 0, update, &env);
	mlx_hook(env.win.win_p, EXIT_BTN, 1L << 0, close_window, &env);
	mlx_loop(env.win.mlx_p);
	return (0);
}
