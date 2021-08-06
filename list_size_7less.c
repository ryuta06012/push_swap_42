#include "push_swap.h"

void	find_min_value(t_dlist *nil_a, t_dlist *current, int *int_min)
{
	while (current != nil_a)
	{
		if (current->value < *int_min)
			*int_min = current->value;
		current = current->next;
	}
}

static void	count_to_min(t_dlist *nil_a, t_dlist *current, int *count, int min)
{
	while (current->value != min && current != nil_a)
	{
		current = current->next;
		*count += 1;
	}
}

void	distance_bet_min(t_dlist *current, t_data *result, int *count)
{
	if ((*count > 1) && *count <= result->len_a / 2)
	{
		*count -= 1;
		while (*count)
		{
			dlist_rorate(current);
			write(1, "ra\n", 3);
			*count -= 1;
		}
	}
	else if (*count > result->len_a / 2)
	{
		*count -= 1;
		while (*count < result->len_a)
		{
			dlist_rrorate(current);
			write(1, "rra\n", 4);
			*count += 1;
		}
	}
}

void	find_min_a_to_b(t_dlist *nil_a, t_dlist *nil_b, t_data *result)
{
	t_dlist	*current;
	int		int_min;
	int		count;

	if ((result->len == 4 && result->len_a == 2) || (result->len == 5 && result->len_a == 3) \
	|| (result->len == 6 && result->len_a == 3))
		return ;
	int_min = INT_MAX;
	current = nil_a->next;
	find_min_value(nil_a, current, &int_min);
	current = nil_a->next;
	count = 1;
	count_to_min(nil_a, current, &count, int_min);
	while (current != nil_a)
		current = current->next;
	distance_bet_min(current, result, &count);
	push_b(current, nil_b);
	result->len_a -= 1;
	find_min_a_to_b(current, nil_b, result);
}

void	short_sort_7less(t_dlist *nil_a, t_dlist *nil_b, t_data *result)
{
	t_dlist	*current_b;
	int		len_a;
	int		len_b;

	find_min_a_to_b(nil_a, nil_b, result);
	len_a = dlist_size(nil_a);
	len_b = dlist_size(nil_b);
	short_stack_sort(nil_a, len_a);
	current_b = nil_b->next;
	while (current_b != nil_b)
	{
		current_b = current_b->prev;
		push_a(nil_a, current_b);
		write(1, "pa\n", 3);
		current_b = current_b->next;
	}
}
