#include "push_swap.h"

int	sortcheck(t_dlist *cur, t_dlist *nil_a, t_dlist *nil_b, t_data *res)
{
	cur = cur->next;
	while (cur != nil_b)
	{
		if (cur->value < cur->next->value)
			cur = cur->next;
		else
			break ;
	}
	if (cur->next == nil_b)
	{
		res->len_b = dlist_size(cur);
		while (cur != nil_b)
			cur = cur->next;
		while (res->len_b)
		{
			command_bottom_push_b(cur, nil_a);
			res->len_b--;
		}
		return (0);
	}
	return (1);
}

void	len_judge(t_dlist *cur, t_dlist *nil_a, t_dlist *nil_b, t_data *res)
{
	while (cur != nil_b)
		cur = cur->next;
	res->len_b = dlist_size(cur);
	if (res->len_b > 3)
		half_b_set(nil_a, cur, res);
	else if (res->len_b > 0 && res->len_b <= 3)
		short_stack_sort_b(cur, res->len_b);
}

void	count_judge(t_dlist *cur, t_dlist *nil_b, t_data *result, int count)
{
	if (count > 1)
	{
		count -= 1;
		while (count)
		{
			rorate_and_write(cur);
			count--;
		}
		push_b(cur, nil_b);
		result->len_a -= 1;
	}
	else if (count == 1)
	{
		push_b(cur, nil_b);
		result->len_a -= 1;
	}
}

void	next_value_min(t_dlist *current, t_dlist *nil_a, int int_min, int *len)
{
	if (current->next->value == (int_min + 1))
	{
		command_bottom_push_b(current, nil_a);
		len--;
	}
}
