#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void do_ops(t_stack **stack_a)
{
	int size;
	t_stack *stack_b;
	int index;

	stack_b = NULL;
	size = list_size(stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
	{
		rank_list(stack_a);
		index = find_index(*stack_a);
		push_min_to_top(stack_a, size, index);
		pb(stack_a, &stack_b);
		sort_three(stack_a);
		pa(stack_a, &stack_b);
	}
	else if (size == 5)
		sort_five(stack_a, &stack_b);
	else
		turk_sort(stack_a, &stack_b);
}


int main(int argc, char **argv)
{
	int i;
	t_stack *stack_a;

	i = 1;
	stack_a = NULL;
	if (argc <= 1)
		return (0);
	while (argv[i])
	{
		if (handle_string(&stack_a, argv[i]))
			i++;
		else
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
	}
	if (!valid_list(stack_a))
		return (0);
	do_ops(&stack_a);
	free_list(stack_a);
	return (0);
}
