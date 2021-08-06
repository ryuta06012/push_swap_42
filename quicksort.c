#include "push_swap.h"

void	dlist_three_sort_b(t_dlist *nil)
{
	if (nil->next->value <= nil->next->next->value && nil->next->next->value \
	<= nil->next->next->next->value)
		return ;
	else if ((nil->next->value > nil->next->next->value) && \
	(nil->next->next->value < nil->next->next->next->value) && \
	(nil->next->value < nil->next->next->next->value))
		swap_b(nil);
	else if ((nil->next->value > nil->next->next->value) && \
	(nil->next->next->value > nil->next->next->next->value) && \
	(nil->next->value > nil->next->next->next->value))
		swap_rrorate_b(nil);
	else if ((nil->next->value > nil->next->next->value) && \
	(nil->next->next->value < nil->next->next->next->value) && \
	(nil->next->value > nil->next->next->next->value))
		rorate_b(nil);
	else if ((nil->next->value < nil->next->next->value) && \
	(nil->next->next->value > nil->next->next->next->value) && \
	(nil->next->value < nil->next->next->next->value))
		swap_rorate_b(nil);
	else if ((nil->next->value < nil->next->next->value) && \
	(nil->next->next->value > nil->next->next->next->value) && \
	(nil->next->value > nil->next->next->next->value))
		rrorate_b(nil);
}

void	short_stack_sort_b(t_dlist *nil, int len)
{
	if (len < 2)
		return ;
	if (len == 2 && (nil->next->value > nil->next->next->value))
	{
		dlist_swap_first2(nil);
		write(1, "sb\n", 3);
	}
	if (len == 3)
		dlist_three_sort_b(nil);
}

void	half_a_set(t_dlist *nil_a, t_dlist *nil_b, t_data *result)
{
	t_dlist	*current;
	int		val_mid;
	int		class_len;
	int		class_num;

	val_mid = find_value_mid(nil_a, result->len_a);
	class_len = by_class_len(nil_a);
	current = nil_a->next;
	class_num = current->class;
	current = nil_a;
	if (class_len > 3 && current->next->class == 0 && result->turn == 0)
	{
		result->turn += 1;
		first_sort(nil_a, nil_b, result, val_mid);
	}		
	else if (class_len > 2 && result->turn != 0)
		class_len_3over(current, nil_b, class_len, class_num);
	else if (class_len == 2)
		class_len_2(current, result);
	else if (class_len == 1)
	{
		current->next->class = -1;
		rorate_and_write(current);
	}
	result->len_b = dlist_size(nil_b);
}

void	half_b_set(t_dlist *nil_a, t_dlist *nil_b, t_data *result)
{
	t_dlist	*current;
	int		i;
	int		flag;

	result->len_b = dlist_size(nil_b);
	current = nil_b;
	current = current->next;
	flag = first_sort_b(current, nil_a, nil_b, result);
	if (flag == 0)
		return ;
	while (current != nil_b)
		current = current->next;
	if (result->len_b > 0 && result->len_b <= 3)
	{
		short_stack_sort_b(nil_b, result->len_b);
		return ;
	}
	cmd_b(current, nil_a, nil_b, result);
	i = sortcheck(current, nil_a, nil_b, result);
	if (i == 0)
		return ;
	len_judge(current, nil_a, nil_b, result);
}

void	quicksort(t_dlist *nil_a, t_dlist *nil_b, t_data *result)
{
	int		len_b;

	half_a_set(nil_a, nil_b, result);
	half_b_set(nil_a, nil_b, result);
	len_b = dlist_size(nil_b);
	while (len_b)
	{
		nil_b->next->class = -1;
		bottom_push_b(nil_a, nil_b);
		write(1, "pa\nra\n", 6);
		len_b--;
	}
	if (nil_a->next->class != -1)
		quicksort(nil_a, nil_b, result);
}
