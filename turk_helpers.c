#include "push_swap.h"

t_stack	*find_min(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*min_node;

	if (!*stack_a)
		return (0);
	min_node = *stack_a;
	current = min_node;
	while (current)
	{
		if (current->content < min_node->content)
		{
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

t_stack	*find_max(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*max_node;

	if (!*stack_a)
		return (0);
	max_node = *stack_a;
	current = max_node;
	while (current)
	{
		if (current->content > max_node->content)
		{
			max_node = current;
		}
		current = current->next;
	}
	return (max_node);
}

void	set_current_position(t_stack **stack_a)
{
	t_stack	*current;
	int		pos;

	pos = 0;
	if (!*stack_a)
		return ;
	current = *stack_a;
	while (current)
	{
		current->pos = pos;
		current = current->next;
		pos++;
	}
}

void	find_target_node(t_stack **stack_a, t_stack *node_b)
{
	t_stack	*current;
	t_stack *best_match;

	best_match = NULL;
	if (!*stack_a)
		return ;
	current = *stack_a;
	while (current)
	{
		if (current->content > node_b->content)
		{
			if (!best_match || (best_match->content > current->content))
				best_match = current;
		}
		current = current->next;
	}
	if (!best_match)
	{
		best_match = find_min(stack_a);
	}
	node_b->target_pos = best_match->pos;
}


void assign_targets_b (t_stack *stack_a, t_stack *stack_b)
{
	t_stack *current_b;

	if (!stack_a || !stack_b)
	{
		return;
	}
	set_current_position(&stack_a);
	set_current_position(&stack_b);
	current_b = stack_b;
	while (current_b)
	{
		find_target_node(&stack_a, current_b);
		current_b = current_b->next;
	}
}