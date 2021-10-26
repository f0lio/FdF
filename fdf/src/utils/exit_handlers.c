
#include "fdf.h"

void safe_free(void **ptr)
{
	if (ptr == NULL || *ptr == NULL)
		return ;
	free(*ptr);
}

void	clean_exit(t_env *env, int exit_code)
{
	int		i;
	void (*func)(void**);

	if (env->matrix.data)
	{
		i = env->matrix.rows;
		while (--i > -1)
			safe_free((void**)&env->matrix.data[i]);
		safe_free((void**)&env->matrix.data);
	}
	if (env->file.lines)
	{
		func = (void (*)(void **))destroy_string;
		destroy_list(&env->file.lines, func);
	}
	exit(exit_code);
}

void	error_exit(t_env *env, char *msg)
{
	put_str("Error\n");
	put_str(msg);
	put_char('\n');
	clean_exit(env, EXIT_FAILURE);
}

int		close_window(t_env *env)
{
	mlx_destroy_image(env->win.mlx_p, env->win.img_p);
	mlx_destroy_window(env->win.mlx_p, env->win.win_p);
	clean_exit(env, EXIT_SUCCESS);
	return (0);
}