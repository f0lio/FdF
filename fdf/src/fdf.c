#include "fdf.h"

void	setup(t_env *env)
{
	if (env->argc != 2)
		error_exit(env, ERR_ARG);
	env->horizontal_shift = env->win.width / 3;
	env->vertical_shift = env->win.height / 3;
	read_map(env);
	parse_map(env);
	normalize_alt(env, get_resp_ratio(env));
	env->zoom = get_min(env->win.width / env->matrix.cols / 1.5,
			env->win.height / env->matrix.rows / 1.5);
}

void	start_engine(t_env *env)
{
	set_window(env);
	set_event_hooks(env);
	render(env);
	mlx_loop(env->win.mlx_p);
}

void	update(t_env *env)
{
	clear_window(env);
	render(env);
}

int	main(int argc, const char **argv)
{
	t_env	env;

	if (argc != 2)
	{
		put_str("Error\nYou need to provide one valid map file\n");
		return (EXIT_FAILURE);
	}
	init_env(&env, argc, argv);
	setup(&env);
	start_engine(&env);
	return (0);
}
