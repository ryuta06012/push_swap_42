#include "push_swap.h"

void	dlist_swap_first2(t_dlist *nil)
{
	t_dlist	*first;
	t_dlist	*second;

	if (dlist_size(nil) < 2)
		return ;
	first = nil->next;
	second = first->next;
	nil->next = second;
	second->prev = nil;
	first->prev = second;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
}

void	dlist_rorate(t_dlist *nil)
{
	t_dlist	*top;

	top = nil->next;
	nil->next = top->next;
	top->next->prev = nil;
	nil->prev->next = top;
	top->prev = nil->prev;
	top->next = nil;
	nil->prev = top;
}

void	dlist_rrorate(t_dlist *nil)
{
	t_dlist	*lowest;

	lowest = nil->prev;
	lowest->prev->next = nil;
	nil->prev = lowest->prev;
	lowest->next = nil->next;
	lowest->prev = nil;
	nil->next->prev = lowest;
	nil->next = lowest;
}

void	list_swap_top(t_dlist *nil)
{
	t_dlist	*top;
	t_dlist	*second;

	if (dlist_size(nil) < 2)
		return ;
	top = nil->next;
	second = top->next;
	nil->next = second;
	second->prev = nil;
	top->prev = second;
	top->next = second->next;
	second->next->prev = top;
	second->next = top;
}
