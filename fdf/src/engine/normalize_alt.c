#include "fdf.h"

float	get_resp_ratio(t_env *env)
{
	if (env->max_z > 100)
		return (.8);
	else if (env->max_z > 50)
		return (.6);
	else if (env->max_z > 30)
		return (.8);
	else if (env->max_z > 20)
		return (.7);
	else if (env->max_z >= 10)
		return (2);
	else if (env->max_z > 4)
		return (4);
	else
		return (1);
}

void	normalize_alt(t_env *env, float ratio)
{
	int	x;
	int	y;

	if (ratio == 1)
		return ;
	y = 0;
	while (y < env->matrix.rows)
	{
		x = 0;
		while (x < env->matrix.cols)
		{
			env->matrix.data[y][x].z *= ratio;
			x++;
		}
		y++;
	}
}
