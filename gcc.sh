#gcc command.c command_utils.c command_utils1.c ft_atoi.c list_size_7less.c push_swap.c push_swap_utils.c push_swap.h quicksort_utils.c quicksort_utils1.c quicksort_utils2.c quicksort_utils3.c quicksort_utils4.c quicksort.c slist.c three_sort_utils_b.c three_sort_utils_a.c
make
#ARG=$(jot -r -s " " 100 -2147483648 2147483647); ./push_swap $ARG | ./checker $ARG
seq 1 1000 | shuf | head -n 100 | xargs echo | xargs ./push_swap
cd push_swap_tester
#python3 push_swap_tester.py -l 500 -c 500
python3 push_swap_tester.py --gen -r -2147483648 2147483647 -l 10