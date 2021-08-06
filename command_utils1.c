#include "push_swap.h"

void	rorate_and_write(t_dlist *nil)
{
	dlist_rorate(nil);
	write(1, "ra\n", 3);
}

void	command_push_a(t_dlist *current, t_dlist *nil_a, int *len, int val_max)
{
	current->next->class = val_max;
	push_a(nil_a, current);
	write(1, "pa\n", 3);
	*len -= 1;
}
