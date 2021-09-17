
#include "fdf.h"

void    set_zoom(int zoom, t_vec *line)
{
    line->start.x *= zoom;
    line->start.y *= zoom;
    line->end.x *= zoom;
    line->end.y *= zoom;
}