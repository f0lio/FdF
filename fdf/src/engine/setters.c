
#include "fdf.h"

void    set_point(t_point *p, int x, int y)
{
    p->x = x;
    p->y = y;
}

void    set_line(t_env *env, t_vec *line, int x, int y)
{
    set_point(&line->end, x, y);
    set_zoom(env->zoom, line);
}