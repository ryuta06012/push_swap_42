NAME = push_swap

SRCS = command.c \
	command_utils.c \
	command_utils1.c \
	ft_atoi.c \
	list_size_7less.c \
	quicksort_utils.c \
	quicksort_utils1.c \
	quicksort_utils2.c \
	quicksort_utils3.c \
	quicksort_utils4.c \
	quicksort.c \
	slist.c \
	three_sort_utils_a.c \
	three_sort_utils_b.c \
	push_swap.c \
	push_swap_utils.c

HEADER = push_swap.h

CC = gcc

CFLAGS = -Wextra -Werror -Wall

RM = rm -f

all:	$(NAME)

$(NAME):	$(SRCS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean: 
	$(RM) $(REG_OBJS)
fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re