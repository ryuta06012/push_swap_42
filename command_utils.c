#include "push_swap.h"

void	dlist_push(t_dlist *nil, t_dlist *element)
{
	nil->next->prev = element;
	element->next = nil->next;
	element->prev = nil;
	nil->next = element;
}

t_dlist	*dlist_pop(t_dlist *nil)
{
	t_dlist	*element;

	if (!dlist_size(nil))
		return (NULL);
	element = nil->next;
	nil->next = element->next;
	element->next->prev = nil;
	return (element);
}

void	push_b(t_dlist *nil_a, t_dlist *nil_b)
{
	t_dlist	*top;

	top = dlist_pop(nil_a);
	if (!top)
		return ;
	dlist_push(nil_b, top);
	write(1, "pb\n", 3);
}

void	push_a(t_dlist *nil_a, t_dlist *nil_b)
{
	t_dlist	*top;

	top = dlist_pop(nil_b);
	if (!top)
		return ;
	dlist_push(nil_a, top);
}

void	bottom_push_b(t_dlist *nil_a, t_dlist *nil_b)
{
	t_dlist	*top;

	top = dlist_pop(nil_b);
	if (!top)
		return ;
	dlist_push(nil_a, top);
	dlist_rorate(nil_a);
}
