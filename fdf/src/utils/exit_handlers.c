
#include "fdf.h"

void	clean_exit(t_env *env, int exit_code)
{
    //clean mem
    //clean mlx 
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

		mlx_destroy_window(env->win.mlx_p, env->win.win_p);
	clean_exit(env, EXIT_SUCCESS);
	return (0);
}