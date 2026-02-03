#include "push_swap.h"
#include "libft.h"

void sort_three(t_stack **stack_a)
{
	t_stack *temp;
	if (list_size(stack_a) != 3)
		return;
	rank_list(stack_a);
	temp = *stack_a;
	if (temp->rank > temp->next->rank && temp->rank > temp->next->next->rank)
	{
		ra(stack_a);
	}
	else if (temp->next->rank > temp->rank && temp->next->rank > temp->next->next->rank)
	{
		rra(stack_a);
	}
	temp = *stack_a;
	if (temp->rank > temp->next->rank)
	{
		sa(stack_a);
	}
}

int find_index(t_stack *stack_a)
{
	t_stack *temp;
	int index;

	index = 0;
	if (!stack_a)
		return (0);
	temp = stack_a;
	while (temp && temp->rank != 0)
	{
		temp = temp->next;
		index++;
	}
	return (index);
}

void push_min_to_top(t_stack **stack_a, int size, int index)
{
	int rotation_steps;

	rotation_steps = 0;
	if (!*stack_a)
		return;
	rank_list(stack_a);
	rotation_steps = size - index;
	if (index <= size / 2)
	{
		while (index > 0)
		{
			ra(stack_a);
			index--;
		}
	}
	else
	{
		while (rotation_steps > 0)
		{
			rra(stack_a);
			rotation_steps--;
		}
	}
}

void sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int stack_size;
	t_stack *temp;
	int index;

	stack_size = list_size(stack_a);
	if (!*stack_a)
		return;
	temp = *stack_a;
	rank_list(stack_a);
	index = find_index(*stack_a);
	push_min_to_top(stack_a, stack_size, index);
	pb(stack_a, stack_b);
	rank_list(stack_a);
	index = find_index(*stack_a);
	stack_size = list_size(stack_a);
	push_min_to_top(stack_a, stack_size, index);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	temp = *stack_a;
	rank_list(stack_a);
	if (temp->rank > temp->next->rank)
		sa(stack_a);
}
