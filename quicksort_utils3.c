#include "push_swap.h"

void	bottom_push_rorate_b(t_dlist *current, t_dlist *nil_a, int *len)
{
	current->next->class = -1;
	bottom_push_b(nil_a, current);
	dlist_rorate(current);
	write(1, "pa\nrr\n", 6);
	*len -= 1;
}

void	command_bottom_push_b(t_dlist *current, t_dlist *nil_a)
{
	current->next->class = -1;
	bottom_push_b(nil_a, current);
	write(1, "pa\nra\n", 6);
}

void	command_rorate_b(t_dlist *current, int *len)
{
	dlist_rorate(current);
	write(1, "rb\n", 3);
	*len -= 1;
}

void	value_set_up(int *val_mid, int *val_max, t_dlist *nil_b, t_data *result)
{
	*val_mid = find_value_mid(nil_b, result->len_b);
	*val_max = find_value_max(nil_b);
	result->len_b = dlist_size(nil_b);
}

void	cmd_b(t_dlist *cur, t_dlist *nil_a, t_dlist *nil_b, t_data *res)
{
	int	len;
	int	int_min;
	int	val_max;
	int	val_mid;

	value_set_up(&val_mid, &val_max, nil_b, res);
	len = res->len_b;
	while (len > 0)
	{
		int_min = INT_MAX;
		find_int_min_b(cur, nil_b, &int_min);
		if (cur->next->value > val_mid)
			command_push_a(cur, nil_a, &len, val_max);
		else if (cur->next->value == int_min)
		{
			if (cur->next->next->value <= val_mid)
				bottom_push_rorate_b(cur, nil_a, &len);
			else
				command_bottom_push_b(cur, nil_a);
			next_value_min(cur, nil_a, int_min, &len);
			len--;
		}
		else if (cur->next->value <= val_mid)
			command_rorate_b(cur, &len);
	}
}
