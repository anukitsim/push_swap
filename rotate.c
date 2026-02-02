#include "push_swap.h"
#include "ft_printf.h"

int rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (!*stack || !(*stack)->next)
		return (0);
	first = *stack;
	last = last_node(stack);
	*stack = first->next;
	first->next->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	return (1);
}

void ra(t_stack **stack_a)
{
	if (rotate(stack_a))
		ft_printf("ra\n");
}

void rb(t_stack **stack_b)
{
	if (rotate(stack_b))
		ft_printf("rb\n");
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
	if (rotate(stack_a) || rotate(stack_b))
		ft_printf("rr\n");
}

