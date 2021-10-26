
#include "fdf.h"

void	pxl(t_env *env, t_point *p)
{
	int index;

	if (p->x >= env->win.width || p->x < 0)
		return ;
	if (p->y >= env->win.height || p->y < 0)
		return ;
	index = (int)p->x + env->win.width * (int)p->y;
	env->win.img_d[index] = p->color;
}

void	set_window(t_env *env)
{
	t_win	*win;

	win = &env->win;
	win->mlx_p = mlx_init();
	if (win->mlx_p == NULL)
		error_exit(env, ERR_MLX_WIN);
	win->win_p = mlx_new_window(
		win->mlx_p, win->width, win->height, PROGRAM_NAME);
	win->img_p = mlx_new_image(
		win->mlx_p, win->width, win->height);
	win->img_d = (int*)mlx_get_data_addr(
		win->img_p, &win->bpp, &win->size_line, &win->endian);
}

void	update_window(t_env *env)
{
	// mlx_clear_window(env->win.mlx_p, env->win.win_p);
	mlx_put_image_to_window(
		env->win.mlx_p, env->win.win_p, env->win.img_p, 0, 0);
}

void	clear_window(t_env *env)
{
	t_point p;

	p.y = 0;
	p.color = BLACK;
	while (p.y < env->win.height)
	{
		p.x = -1;
		while (++p.x < env->win.width)
			pxl(env, &p);
		p.y++;
	}
}
