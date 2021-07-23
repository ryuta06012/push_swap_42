#include "push_swap.h"

void	swap_a(t_dlist *nil_a)
{
	dlist_swap_first2(nil_a);
	write(1, "sa\n", 3);
}

void	swap_rrorate_a(t_dlist *nil_a)
{
	dlist_swap_first2(nil_a);
	dlist_rrorate(nil_a);
	write (1, "sa\nrra\n", 7);
}

void	rorate_a(t_dlist *nil_a)
{
	dlist_rorate(nil_a);
	write (1, "ra\n", 3);
}

void	swap_rorate_a(t_dlist *nil_a)
{
	dlist_swap_first2(nil_a);
	dlist_rorate(nil_a);
	write (1, "sa\nra\n", 6);
}

void	rrorate_a(t_dlist *nil_a)
{
	dlist_rrorate(nil_a);
	write (1, "rra\n", 4);
}
