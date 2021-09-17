
#include "fdf.h"

void draw_line(t_env *env, t_vec *line)
{
    int     dx;
    int     dy;
    int     d;
    t_point p;

    p.color = line->color;
    dx = line->end.x - line->start.x;
    dy = line->end.y - line->start.y;
    p.x = line->start.x;
    p.y = line->start.y;
    d = 2 * dy - dx;
    while (p.x < line->end.x)
    {
        pxl(env, &p);
        if (d >= 0)
        {
            p.y++;
            d += 2 * dy - 2 * dx;
        }
        else
            d += 2 * dy;
        p.x++;
    }
}
