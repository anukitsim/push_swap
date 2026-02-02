#include "push_swap.h"
#include "ft_printf.h"

int swap(t_stack **stack_a)
{
	t_stack *first;
	t_stack *second;

	if (*stack_a)
	{
		first = *stack_a;
		if (first->next)
			second = first->next;
		else
			return (0);
		if (!second->next)
			first->next = NULL;
		else
		{
			first->next = second->next;
			second->next->previous = first;
		}
		first->previous = second;
		second->next = first;
		second->previous = NULL;
		*stack_a = second;
		return (1);
	}
	return (0);
}

void sa(t_stack **stack_a)
{
	if (swap(stack_a))
		ft_printf("sa\n");
}

void sb(t_stack **stack_b)
{
	if (swap(stack_b))
		ft_printf("sb\n");
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
	if (swap(stack_a) || swap(stack_b))
		ft_printf("ss\n");
}
