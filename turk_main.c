/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsimint <atsimint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:26:13 by atsimint          #+#    #+#             */
/*   Updated: 2026/02/02 19:32:47 by atsimint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	stack_a_size;
	int	stack_b_size;

	stack_a_size = list_size(&stack_a);
	stack_b_size = list_size(&stack_b);
	while (stack_b)
	{
		if (stack_b->pos <= stack_b_size / 2)
			stack_b->cost_b = stack_b->pos;
		else
			stack_b->cost_b = (stack_b_size - stack_b->pos) * (-1);
		if (stack_b->target_pos <= stack_a_size / 2)
			stack_b->cost_a = stack_b->target_pos;
		else
			stack_b->cost_a = (stack_a_size - stack_b->target_pos) * (-1);
		stack_b = stack_b->next;
	}
}

t_stack	*find_cheapest(t_stack *stack_b)
{
	t_stack	*cheapest_node;
	int		current_cost;
	int		cheapest;

	current_cost = 0;
	cheapest = INT_MAX;
	cheapest_node = NULL;
	while (stack_b)
	{
		if (stack_b->cost_a > 0 && stack_b->cost_b > 0)
			current_cost = cost_max(stack_b->cost_a, stack_b->cost_b);
		else if (stack_b->cost_a < 0 && stack_b->cost_b < 0)
			current_cost = cost_max(cost_abs(stack_b->cost_a),
					cost_abs(stack_b->cost_b));
		else
			current_cost = cost_abs(stack_b->cost_a)
				+ cost_abs(stack_b->cost_b);
		if (current_cost < cheapest)
		{
			cheapest = current_cost;
			cheapest_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (cheapest_node);
}


void	move_cheapest(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	rotate_both(stack_a, stack_b, cheapest);
	rotation_a(stack_a, cheapest);
	rotation_b(stack_b, cheapest);
	pa(stack_a, stack_b);
}

void turk_sort (t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cheapest;

	cheapest = NULL;
	while (*stack_b)
	{
		assign_targets_b(*stack_a, *stack_b);
		calc_cost(*stack_a, *stack_b);
		cheapest = find_cheapest(*stack_b);
		move_cheapest(stack_a, stack_b, cheapest);
	}
	final_rotation(stack_a);
}


