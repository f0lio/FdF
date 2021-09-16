
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