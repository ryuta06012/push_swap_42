#include "push_swap.h"

void	class_len_2(t_dlist *current, t_data *result)
{
	if (current->next->value > current->next->next->value)
	{
		dlist_swap_first2(current);
		dlist_size(current);
		current->next->class = -1;
		dlist_rorate(current);
		current->next->class = -1;
		dlist_rorate(current);
		write(1, "sa\nra\nra\n", 9);
		result->count += 3;
		result->len_a -= 2;
	}
	else
	{
		current->next->class = -1;
		dlist_rorate(current);
		current->next->class = -1;
		dlist_rorate(current);
		write(1, "ra\nra\n", 6);
		result->count += 2;
		result->len_a -= 2;
	}
}

int	find_value_min(t_dlist *nil, int class_len)
{
	t_dlist	*current;
	int		int_min;
	int		len;

	int_min = INT_MAX;
	current = nil->next;
	len = class_len;
	while (len)
	{
		if (current->value < int_min)
			int_min = current->value;
		current = current->next;
		len--;
	}
	while (current != nil)
		current = current->next;
	return (int_min);
}

int	nil_b_value_comp(t_dlist *nil_b, int num)
{
	t_dlist	*current_b;

	current_b = nil_b->next;
	while (current_b != nil_b)
	{
		if (current_b->value < num)
		{
			while (current_b != nil_b)
				current_b = current_b->next;
			return (0);
		}
		current_b = current_b->next;
	}
	return (1);
}
