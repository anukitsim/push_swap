/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anukitsimintia <anukitsimintia@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:26:13 by atsimint          #+#    #+#             */
/*   Updated: 2026/02/05 14:19:02 by anukitsimin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a)
		return;
	while (list_size(stack_a) > 3)
	{
		pb(stack_a, stack_b);
	}
}

void turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cheapest;

	cheapest = NULL;
	push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		assign_targets_b(*stack_a, *stack_b);
		calc_cost(*stack_a, *stack_b);
		cheapest = find_cheapest(*stack_b);
		if (cheapest)
			move_cheapest(stack_a, stack_b, cheapest);
	}
	final_rotation(stack_a);
}
