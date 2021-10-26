#include "fdf.h"

float	get_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	get_min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

int	skip_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == c)
		i++;
	return (i);
}

void	free_splited_items(char **items, int size)
{
	if (!items)
		return ;
	while (--size > -1)
	{
		free(items[size]);
		items[size] = NULL;
	}
	free(items);
	items = NULL;
}

char	**str_split_wrapper(t_env *env, char *pts, char c, int *items_count)
{
	char	**items;

	items = str_split(pts, c, items_count);
	if (!items)
		error_exit(env, ERR_INV_MAP);
	return (items);
}
