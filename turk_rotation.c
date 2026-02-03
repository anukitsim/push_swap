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

void final_rotation (t_stack **stack_a)
{
	t_stack *min_node;
	int size;
	int move_count;

	move_count = 0;
	set_current_position(stack_a);
	min_node = find_min(stack_a);
	size = list_size(stack_a);
		if (min_node->pos < size/2)
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
