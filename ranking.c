#include "push_swap.h"

void rank_list(t_stack **stack_a)
{
	t_stack *current;
	t_stack *checker;
	int count;

	if (!*stack_a)
		return;
	current = *stack_a;
	while (current)
	{
		count = 0;
		checker = *stack_a;
		while (checker)
		{
			if (current->content > checker->content)
				count++;
			checker = checker->next;
		}
		current->rank = count;
		current = current->next;
	}
}
