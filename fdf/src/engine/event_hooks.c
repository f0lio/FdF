
#include "fdf.h"

void    set_event_hooks(t_env *env)
{
    mlx_hook(env->win.win_p, 2, 1L << 0, key_hook, env);
	mlx_hook(env->win.win_p, EXIT_BTN, 1L << 0, close_window, env);
    mlx_mouse_hook (env->win.win_p, mouse_hook, env);    
}

static
int mouse_hook(int btn, int x, int y, t_env *env)
{
    env->zoom += (env->zoom < MAX_ZOOM) * (btn == MOUSE_UP) * ZOOM_SPEED;
    env->zoom -= (env->zoom > MIN_ZOOM) * (btn == MOUSE_DOWN) * ZOOM_SPEED;
    if (btn == MOUSE_CLICK)
    {
        env->horizontal_shift += env->clicked * (x - env->old_x);
        env->vertical_shift +=   env->clicked * (y - env->old_y);
        env->old_x = x;
        env->old_y = y;
        env->clicked = !env->clicked;
    }
    update(env);
}

int key_hook(int key, t_env *env)
{
    if (key == KEY_ESC)
        close_window(env);
    env->horizontal_shift += (key == KEY_RIGHT) * SHIFT_SPEED;
    env->horizontal_shift -= (key == KEY_LEFT) * SHIFT_SPEED;
    env->vertical_shift += (key == KEY_DOWN) * SHIFT_SPEED;
    env->vertical_shift -= (key == KEY_UP) * SHIFT_SPEED;
    if (key == KEY_ANGLE_UP)
        env->angle += (PI/180) * 2;
    else if (key == KEY_ANGLE_DOWN)
        env->angle -= (PI/180) * 2;
    else if (key == KEY_V)
        env->iso = !env->iso;
    else if (key == KEY_MINUS)
        env->alt_scale--;
    else if (key == KEY_PLUS)
        env->alt_scale++;
    else if (key == KEY_SPACE)
        env->show_info = !env->show_info;
    update(env);
}
