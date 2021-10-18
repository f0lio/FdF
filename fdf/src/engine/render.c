
#include "fdf.h"

void isometric_projection(float *x, float *y, float z, double angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void set_projection(t_env *env, float *x, float *y)
{
	t_point p;

	p = env->matrix.data[(int)*y][(int)*x];
	*x *= env->zoom;
	*y *= env->zoom;
	if (env->iso)
		isometric_projection(x, y, 	p.z * env->alt_scale, env->angle);
	*x += env->horizontal_shift;
	*y += env->vertical_shift;
}

void project_line(t_env *env, float x, float y, float x1, float y1)
{
	t_point steps;
    t_point p;

	p.color =  env->matrix.data[(int)y][(int)x].color;
	set_projection(env, &x, &y);
	set_projection(env, &x1, &y1);
	steps.x = x1 - x;
	steps.y = y1 - y;
	steps.z = get_max(fabs(steps.x), fabs(steps.y));
	steps.x /= steps.z;
	steps.y /= steps.z;
	p.x = x;
    p.y = y;
	
	while ((int)(p.x - x1) || (int)(p.y - y1))
	{
        pxl(env, &p);
		p.x += steps.x;
		p.y += steps.y;
		if (p.x < 0 || p.x > env->win.width 
            || p.y < 0 || p.y > env->win.height)
			break ;
	}
}

void	render(t_env *env)
{
    int     x;
    int     y;

    y = 0;
    while (y < env->matrix.rows)
    {
        x = 0;
        while (x < env->matrix.cols)
        {
            if (x < env->matrix.cols - 1)
                project_line(env, x, y, x + 1, y);
            if (y < env->matrix.rows - 1)
                project_line(env, x, y, x, y + 1);   
            x++;
        }
        y++;
    }
    update_window(env);
	show_info(env);
}
