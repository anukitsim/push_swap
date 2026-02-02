#include "push_swap.h"
#include "ft_printf.h"

int reverse_rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (!*stack || !(*stack)->next)
		return (0);
	first = *stack;
	last = last_node(stack);
	last->next = first;
	first->previous = last;
	last->previous->next = NULL;
	last->previous = NULL;
	*stack = last;
	return (1);
}

void rra(t_stack **stack_a)
{
	if (reverse_rotate(stack_a))
		ft_printf("rra\n");
}

void rrb(t_stack **stack_b)
{
	if (reverse_rotate(stack_b))
		ft_printf("rrb\n");
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (reverse_rotate(stack_a) || reverse_rotate(stack_b))
		ft_printf("rrr\n");
}
