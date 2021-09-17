
#include "fdf.h"

void    render(t_env *env)
{
    t_vec   line;
    int     x;
    int     y;

    reset_vec(&line);
    y = 0;
    while (y < env->matrix.rows)
    {
        x = 0;
        while (x < env->matrix.cols)
        {
            set_point(&line.start, x, y);
            set_line(env, &line, x + 1, y);
            draw_line(env, &line);

            set_line(env, &line, x, y + 1);
            draw_line(env, &line);
            
            x++;
        }
        y++;
    }
    update_window(env);
}

