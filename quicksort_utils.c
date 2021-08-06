#include "push_swap.h"

int	find_value_mid(t_dlist *nil, int len)
{
	t_dlist	*current;
	long	stock;
	int		mid;
	int		i;

	current = nil->next;
	stock = 0;
	i = 0;
	while (i < len)
	{
		stock += current->value;
		current = current->next;
		i++;
	}
	mid = stock / len;
	current = nil;
	return (mid);
}

int	find_value_max(t_dlist *nil)
{
	t_dlist	*current;
	int		int_max;

	int_max = INT_MIN;
	current = nil->next;
	while (current != nil)
	{
		if (current->value > int_max)
			int_max = current->value;
		current = current->next;
	}
	return (int_max);
}

int	by_class_len(t_dlist *nil_a)
{
	t_dlist	*current;
	int		i;
	int		class_num;

	i = 0;
	current = nil_a->next;
	class_num = current->class;
	while (current->class == class_num && current != nil_a)
	{
		current = current->next;
		i++;
	}
	while (current != nil_a)
		current = current->next;
	return (i);
}

int	class_num_len_zero(t_dlist *nil)
{
	t_dlist	*current;
	int		i;

	i = 0;
	current = nil->next;
	while (current->class != 0 && current != nil)
		current = current->next;
	while (current->class == 0 && current != nil)
	{
		current = current->next;
		i++;
	}
	while (current != nil)
		current = current->next;
	return (i);
}
