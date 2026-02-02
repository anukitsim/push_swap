#include "push_swap.h"
#include "ft_printf.h"

int push(t_stack **src, t_stack **dest)
{
	t_stack *top;

	if (!*src)
		return (0);
	top = *src;
	*src = top->next;
	if (*src)
		top->next->previous = NULL;
	top->next = *dest;
	top->previous = NULL;
	if (*dest)
		(*dest)->previous = top;
	*dest = top;
	return (1);
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_b, stack_a))
		ft_printf("pa\n");
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_a, stack_b))
		ft_printf("pb\n");
}
