#include "push_swap.h"

void	rotate_both(t_stack **stack_a, t_stack **stack_b,
		t_stack *cheapest_node)
{
	if (!*stack_a || !*stack_b)
		return ;
	while (cheapest_node->cost_a > 0 && cheapest_node->cost_b > 0)
	{
		rr(stack_a, stack_b);
		cheapest_node->cost_a--;
		cheapest_node->cost_b--;
	}
	while (cheapest_node->cost_a < 0 && cheapest_node->cost_b < 0)
	{
		rrr(stack_a, stack_b);
		cheapest_node->cost_a++;
		cheapest_node->cost_b++;
	}
}

void rotation_a (t_stack **stack_a, t_stack *cheapest)
{
	while (cheapest->cost_a != 0)
	{
		if (cheapest->cost_a > 0)
		{
			ra(stack_a);
			cheapest->cost_a--;
		}
		else
		{
			rra(stack_a);
			cheapest->cost_a++;
		}
	}
}

void rotation_b (t_stack **stack_b, t_stack *cheapest)
{
	while (cheapest->cost_b != 0)
	{
		if (cheapest->cost_b > 0)
		{
			rb(stack_b);
			cheapest->cost_b--;
		}
		else
		{
			rrb(stack_b);
			cheapest->cost_b++;
		}
	}
}

static void	rotate_min_to_top(t_stack **stack_a, t_stack *min_node, int size)
{
	int	move_count;

	if (min_node->pos < size / 2)
	{
		move_count = min_node->pos;
		while (move_count > 0)
		{
			ra(stack_a);
			move_count--;
		}
	}
	else
	{
		move_count = size - min_node->pos;
		while (move_count > 0)
		{
			rra(stack_a);
			move_count--;
		}
	}
}

void	final_rotation(t_stack **stack_a)
{
	set_current_position(stack_a);
	rotate_min_to_top(stack_a, find_min(stack_a), list_size(stack_a));
}
