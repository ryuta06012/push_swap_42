#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_data
{
	int	len;
	int	turn;
	int	count;
	int	class_num_len;
	int	len_a;
	int	len_b;
}		t_data;

typedef struct s_dlist
{
	struct s_dlist	*next;
	struct s_dlist	*prev;
	int				class;
	int				index;
	long			value;
}		t_dlist;

bool	my_atoi(const char *str, int *num);

t_dlist	*init_dlist(int val);
t_data	*init_data(int len);
t_dlist	*dlist_add(t_dlist *nil, long val);
int		dlist_size(t_dlist *nil);
void	free_dlist(t_dlist *nil);
void	list_swap_top(t_dlist *nil);
void	list_value_min(t_dlist *nil_a, t_dlist *nil_b, int len);
void	dlist_push(t_dlist *nil, t_dlist *element);
t_dlist	*dlist_pop(t_dlist *nil);

void	push_b(t_dlist *nil_a, t_dlist *nil_b);
void	push_a(t_dlist *nil_a, t_dlist *nil_b);
void	bottom_push_b(t_dlist *nil_a, t_dlist *nil_b);
void	dlist_swap_first2(t_dlist *nil);
void	dlist_rorate(t_dlist *nil);
void	dlist_rrorate(t_dlist *nil);

void	short_sort_7less(t_dlist *nil_a, t_dlist *nil_b, t_data *result);
void	quicksort(t_dlist *nil_a, t_dlist *nil_b, t_data *result);
void	short_stack_sort(t_dlist *nil, int len);
void	dlist_three_sort(t_dlist *nil);
void	half_b_set(t_dlist *nil_a, t_dlist *nil_b, t_data *result);
void	dlist_three_sort_b(t_dlist *nil);
void	short_stack_sort_b(t_dlist *nil, int len);

int		find_value_mid(t_dlist *nil, int len);
int		find_value_max(t_dlist *nil);
int		find_value_min(t_dlist *nil, int class_len);
int		by_class_len(t_dlist *nil_a);
int		class_num_len_zero(t_dlist *nil);
void	class_len_2(t_dlist *current, t_data *result);
int		nil_b_value_comp(t_dlist *nil_b, int num);
/*push_swap*/
void	dlist_three_sort(t_dlist *nil);
bool	add_argv_in_stack_check(char **argv, t_dlist *nil);
void	short_stack_sort(t_dlist *nil, int len);
void	sort_judge(t_dlist *nil_a, t_dlist *nil_b, t_data *result, int len);
/*push_swap_utils*/
void	first_check(t_dlist *nil_a, t_dlist *nil_b, t_data *res, char **argv);
/*command_utils1*/
void	rorate_and_write(t_dlist *nil);
/*quicksort_utils2*/
int		count_to_min_value(t_dlist *cur, t_data *res, int *i, int val_mid);
void	first_sort(t_dlist *nil_a, t_dlist *nil_b, t_data *result, int val_mid);
void	class_len_3over(t_dlist *current, t_dlist *nil, int len, int num);
int		first_sort_b(t_dlist *cur, t_dlist *nil_a, t_dlist *nil_b, t_data *res);
void	find_int_min_b(t_dlist *current, t_dlist *nil_b, int *int_min);
/*quicksort_utils3*/
void	command_push_a(t_dlist *current, t_dlist *nil_a, int *len, int val_max);
void	bottom_push_rorate_b(t_dlist *current, t_dlist *nil_a, int *len);
void	command_bottom_push_b(t_dlist *current, t_dlist *nil_a);
void	command_rorate_b(t_dlist *current, int *len);
void	cmd_b(t_dlist *cur, t_dlist *nil_a, t_dlist *nil_b, t_data *res);
void	val_set_up(int *mid, int *val_max, t_dlist *nil_b, t_data *res);
/*quicksort_utils4*/
int		sortcheck(t_dlist *cur, t_dlist *nil_a, t_dlist *nil_b, t_data *res);
void	len_judge(t_dlist *cur, t_dlist *nil_a, t_dlist *nil_b, t_data *res);
void	count_judge(t_dlist *cur, t_dlist *nil_b, t_data *res, int count);
void	next_value_min(t_dlist *current, t_dlist *nil_a, int int_min, int *len);
/*three_sort_utils_b*/
void	swap_b(t_dlist *nil_b);
void	swap_rrorate_b(t_dlist *nil_b);
void	rorate_b(t_dlist *nil_b);
void	swap_rorate_b(t_dlist *nil_b);
void	rrorate_b(t_dlist *nil_b);
/*three_sort_utils_a*/
void	swap_a(t_dlist *nil_a);
void	swap_rrorate_a(t_dlist *nil_a);
void	rorate_a(t_dlist *nil_a);
void	swap_rorate_a(t_dlist *nil_a);
void	rrorate_a(t_dlist *nil_a);

#endif