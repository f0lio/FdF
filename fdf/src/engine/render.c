
#include "fdf.h"

void    render(t_env *env)
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

   update_window(env);
}


