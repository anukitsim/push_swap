#ifndef PUSH_SWAP_H

#define PUSH_SWAP_H

#include <limits.h>
#include <stdlib.h>

typedef struct s_stack
{
	int content;
	struct s_stack *next;
	struct s_stack *previous;
	int rank;

} t_stack;

int is_valid_number(char *s);
long ft_atol(const char *nptr);
t_stack *new_node(int content);
void add_node_end(t_stack **stack_a, t_stack *new_node);
void free_list(t_stack *stack_a);
int valid_node(char **s, t_stack **stack_a);
int is_duplicate(t_stack *stack_a);
int is_sorted(t_stack *stack_a);
int valid_list(t_stack *stack_a);
int handle_string(t_stack **stack_a, char *s);
void free_array(char **arr);
int list_size(t_stack **stack_a);
t_stack *last_node(t_stack **stack_a);
int push(t_stack **src, t_stack **dest);
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);
int reverse_rotate(t_stack **stack);
void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);
void rrr(t_stack **stack_a, t_stack **stack_b);
int swap(t_stack **stack_a);
void sa(t_stack **stack_a);
void sb(t_stack **stack_b);
void ss(t_stack **stack_a, t_stack **stack_b);
int rotate(t_stack **stack);
void ra(t_stack **stack_a);
void rb(t_stack **stack_b);
void rr(t_stack **stack_a, t_stack **stack_b);
void rank_list(t_stack **stack_a);
void sort_three(t_stack **stack_a);
void sort_five(t_stack **stack_a, t_stack **stack_b);
void push_min_to_top(t_stack **stack_a, int size, int index);
int find_index(t_stack *stack_a);
void do_ops(t_stack **stack_a);

#endif
