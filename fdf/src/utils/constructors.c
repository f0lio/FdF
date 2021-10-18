
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
    env->angle = ANGLE;
    env->argc = argc;
    env->argv = argv;
    env->horizontal_shift = 0;
    env->vertical_shift = 0;
    env->old_x = 0;
    env->old_y = 0;
    env->clicked = FALSE;
    env->iso = TRUE;
    env->show_info = FALSE;

    env->alt_scale = 1;
    
    env->matrix.has_colors = FALSE;
    init_file(&env->file);
    init_win(&env->win);
}

void    reset_point(t_point *p)
{
    p->color = DEFAULT_COLOR;
    p->x = 0;
    p->y = 0;
    p->z = 0;
}
