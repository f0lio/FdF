
#include "fdf.h"

t_node	*new_node(void)
{
	t_node	*node;

	node = malloc(sizeof(*node));
	node->data = 0;
	node->next = 0;
	return (node);
}

void	push_back(t_node **list, void *data)
{
	t_node	*new;
	t_node	*tmp;

	new = new_node();
	if (!new)
		return ;
	new->data = data;
	if (*list == 0)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next != 0)
		tmp = tmp->next;
	tmp->next = new;
}
