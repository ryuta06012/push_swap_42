#include "push_swap.h"

static bool	same_value_check(t_dlist *nil_a)
{
	t_dlist	*cur;
	t_dlist	*tmp;

	cur = nil_a->next;
	while (cur != nil_a)
	{
		tmp = cur->next;
		while (tmp != nil_a)
		{
			if (cur->value == tmp->value)
				return (false);
			tmp = tmp->next;
		}
		cur = cur->next;
	}
	return (true);
}

static bool	first_sort_check(t_dlist *nil_a)
{
	t_dlist	*cur;

	cur = nil_a->next;
	while (cur != nil_a)
	{
		if (cur->value < cur->next->value || cur == nil_a->prev)
			cur = cur->next;
		else
			return (true);
	}
	return (false);
}

void	first_check(t_dlist *nil_a, t_dlist *nil_b, t_data *res, char **argv)
{
	if (!add_argv_in_stack_check(argv, nil_a) || !same_value_check(nil_a))
	{
		write(1, "Error\n", 6);
		free_dlist(nil_a);
		free_dlist(nil_b);
		free(res);
		exit (1);
	}
	if (!first_sort_check(nil_a))
	{
		free_dlist(nil_a);
		free_dlist(nil_b);
		free(res);
		exit (1);
	}
}
