
#include "fdf.h"

void controllers(t_env *env, int key)
{
    if (key == KEY_UP)
        env->vertical_shift -= SHIFT_SPEED;
    if (key == KEY_DOWN)
        env->vertical_shift += SHIFT_SPEED;
    if (key == KEY_LEFT)
        env->horizontal_shift -= SHIFT_SPEED;
    if (key == KEY_RIGHT)
        env->horizontal_shift += SHIFT_SPEED;
}
