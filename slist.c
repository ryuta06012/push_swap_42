#include <unistd.h>
#include "push_swap.h"
#include <stdio.h>

t_data	*init_data(int len)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->len = 0;
	new->turn = 0;
	new->count = 0;
	new->class_num_len = 0;
	new->len_a = len;
	new->len_b = 0;
	return (new);
}

t_dlist	*init_dlist(int val)
{
	t_dlist	*nil;

	nil = (t_dlist *)malloc(sizeof(t_dlist));
	if (!nil)
		return (NULL);
	nil->value = val;
	nil->class = 0;
	nil->index = 0;
	nil->next = nil;
	nil->prev = nil;
	return (nil);
}

t_dlist	*dlist_add(t_dlist *nil, long val)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	//printf("val = %ld\n", val);
	new->value = val;
	nil->prev->next = new;
	new->prev = nil->prev;
	new->next = nil;
	nil->prev = new;
	return (new);
}

int	dlist_size(t_dlist *nil)
{
	t_dlist	*tmp;
	int		len;

	tmp = nil->next;
	len = 0;
	while (tmp != nil)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

void	free_dlist(t_dlist *nil)
{
	t_dlist	*current;
	t_dlist	*tmp;

	current = nil->next;
	while (current != nil)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(nil);
}
