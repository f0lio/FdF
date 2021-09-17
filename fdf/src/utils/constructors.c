
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
    env->zoom = ZOOM;
    env->argc = argc;
    env->argv = argv;
    init_file(&env->file);
    init_win(&env->win);
}

void    reset_vec(t_vec *vec)
{
    vec->color = DEFAULT_COLOR;
    reset_point(&vec->start);
    reset_point(&vec->end);
}

void    reset_point(t_point *p)
{
    p->color = DEFAULT_COLOR;
    p->x = 0;
    p->y = 0;
}
