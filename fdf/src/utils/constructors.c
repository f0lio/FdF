
#include "fdf.h"

void    init_win(t_win *win)
{
    win->width = WINDOW_WIDTH;
	win->height = WINDOW_HEIGHT;
	win->win_p = NULL;
	win->mlx_p = NULL;
	win->img_p = NULL;
	win->img_d = NULL;
}

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
    init_win(&env->win);
}
