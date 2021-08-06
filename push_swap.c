#include "push_swap.h"

void	dlist_three_sort(t_dlist *nil)
{
	if (nil->next->value <= nil->next->next->value && nil->next->next->value \
	<= nil->next->next->next->value)
		return ;
	else if ((nil->next->value > nil->next->next->value) && \
	(nil->next->next->value < nil->next->next->next->value) && \
	(nil->next->value < nil->next->next->next->value))
		swap_a(nil);
	else if ((nil->next->value > nil->next->next->value) && \
	(nil->next->next->value > nil->next->next->next->value) && \
	(nil->next->value > nil->next->next->next->value))
		swap_rrorate_a(nil);
	else if ((nil->next->value > nil->next->next->value) && \
	(nil->next->next->value < nil->next->next->next->value) && \
	(nil->next->value > nil->next->next->next->value))
		rorate_a(nil);
	else if ((nil->next->value < nil->next->next->value) && \
	(nil->next->next->value > nil->next->next->next->value) && \
	(nil->next->value < nil->next->next->next->value))
		swap_rorate_a(nil);
	else if ((nil->next->value < nil->next->next->value) && \
	(nil->next->next->value > nil->next->next->next->value) && \
	(nil->next->value > nil->next->next->next->value))
		rrorate_a(nil);
}

bool	add_argv_in_stack_check(char **argv, t_dlist *nil)
{
	t_dlist	*current;
	int		i;
	int		num;
	bool	flag;

	num = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		flag = my_atoi(argv[i], &num);
		current = dlist_add(nil, num);
		if (!flag || !current)
			return (false);
		i++;
	}
	return (true);
}

void	short_stack_sort(t_dlist *nil, int len)
{
	if (len < 2)
		return ;
	if (len == 2 && (nil->next->value > nil->next->next->value))
	{
		dlist_swap_first2(nil);
		write (1, "sa\n", 3);
	}
	if (len == 3)
		dlist_three_sort(nil);
}

void	sort_judge(t_dlist *nil_a, t_dlist *nil_b, t_data *result, int len)
{
	if (len < 4)
		short_stack_sort(nil_a, len);
	else if (len > 3 && len < 7)
		short_sort_7less(nil_a, nil_b, result);
	else if (len > 6)
		quicksort(nil_a, nil_b, result);
}

int	main(int argc, char **argv)
{
	t_data	*result;
	t_dlist	*nil_a;
	t_dlist	*nil_b;
	int		len;

	nil_a = init_dlist(0);
	nil_b = init_dlist(0);
	result = init_data(0);
	len = 0;
	if (!nil_a || !nil_b || !result || argc <= 1)
	{
		free_dlist(nil_a);
		free_dlist(nil_b);
		free(result);
		return (1);
	}
	first_check(nil_a, nil_b, result, argv);
	len = dlist_size(nil_a);
	result->len_a = len;
	result->len = len;
	sort_judge(nil_a, nil_b, result, len);
	free_dlist(nil_a);
	free_dlist(nil_b);
	free(result);
	return (0);
}
