#include "push_swap.h"

void	swap_b(t_dlist *nil_b)
{
	dlist_swap_first2(nil_b);
	write (1, "sb\n", 3);
}

void	swap_rrorate_b(t_dlist *nil_b)
{
	dlist_swap_first2(nil_b);
	dlist_rrorate(nil_b);
	write (1, "sb\nrrb\n", 7);
}

void	rorate_b(t_dlist *nil_b)
{
	dlist_rorate(nil_b);
	write (1, "rb\n", 3);
}

void	swap_rorate_b(t_dlist *nil_b)
{
	dlist_swap_first2(nil_b);
	dlist_rorate(nil_b);
	write (1, "sb\nrb\n", 6);
}

void	rrorate_b(t_dlist *nil_b)
{
	dlist_rrorate(nil_b);
	write (1, "rrb\n", 4);
}
