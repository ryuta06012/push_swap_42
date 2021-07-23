#include "push_swap.h"

int	count_to_min_value(t_dlist *current, t_data *result, int *i, int val_mid)
{
	int	count;

	current = current->next;
	count = 1;
	while (current->value >= val_mid && *i < result->len_a)
	{
		current = current->next;
		count++;
		*i += 1;
	}
	return (count);
}

void	first_sort(t_dlist *nil_a, t_dlist *nil_b, t_data *result, int val_mid)
{
	t_dlist	*current;
	int		i;
	int		j;
	int		count;
	int		len;

	len = result->len_a;
	current = nil_a;
	j = 0;
	while (j < len && result->len_a > (result->len_a / 2))
	{
		i = 0;
		count = count_to_min_value(current, result, &i, val_mid);
		if (i == result->len_a)
			break ;
		while (current != nil_a)
			current = current->next;
		count_judge(current, nil_b, result, count);
		result->len_a = dlist_size(current);
		j++;
	}
}

void	class_len_3over(t_dlist *current, t_dlist *nil, int len, int num)
{
	int	int_min;
	int	judge;

	int_min = find_value_min(current, len);
	while (current->next->class == num)
	{
		judge = nil_b_value_comp(nil, int_min);
		if (current->next->value == int_min && judge == 1)
		{
			current->next->class = -1;
			rorate_and_write(current);
			len -= 1;
			int_min = find_value_min(current, len);
		}
		else
		{
			push_b(current, nil);
			len -= 1;
		}
	}
}

int	first_sort_b(t_dlist *current, t_dlist *nil_a, t_dlist *nil_b, t_data *res)
{
	while (current != nil_b)
	{
		if (current->value < current->next->value)
			current = current->next;
		else
			break ;
	}
	if (current->next == nil_b)
	{
		res->len_b = dlist_size(current);
		while (current != nil_b)
			current = current->next;
		while (res->len_b)
		{
			command_bottom_push_b(current, nil_a);
			res->len_b--;
		}
		return (0);
	}
	return (1);
}

void	find_int_min_b(t_dlist *current, t_dlist *nil_b, int *int_min)
{
	current = current->next;
	while (current != nil_b)
	{
		if (current->value < *int_min)
			*int_min = current->value;
		current = current->next;
	}
}
