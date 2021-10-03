
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
    // printf("%d: (%d, %d)\n", btn, x, y);
    env->zoom += (env->zoom < MAX_ZOOM) * (btn == MOUSE_UP) * ZOOM_SPEED;
    env->zoom -= (env->zoom > MIN_ZOOM) * (btn == MOUSE_DOWN) * ZOOM_SPEED;
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
    update(env);
}
