#include "push_swap.h"
#include "libft.h"

int is_valid_number(char *s)
{
	int i;

	i = 0;
	if (!s || !s[i])
		return (0);
	if (s[i] && (s[i] == '-' || s[i] == '+') && s[i + 1])
		i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int valid_node(char **s, t_stack **stack_a)
{
	long number;
	t_stack *node;

	number = 0;
	if (!is_valid_number(*s))
		return (0);
	number = ft_atol(*s);
	if (INT_MAX < number || INT_MIN > number)
	{
		return (0);
	}
	node = new_node(number);
	if (node)
	{
		add_node_end(stack_a,node);
		return (1);
	}
	return (0);
}

int is_duplicate(t_stack *stack_a)
{
	t_stack *first;
	t_stack *second;

	if (!stack_a)
	{
		return (0);
	}
	first = stack_a;
	while (first)
	{
		second = first->next;
		while (second)
		{
			if (first->content == second->content)
			{
				return (1);
			}
			second = second->next;
		}
		first = first->next;
	}
	return (0);
}

int is_sorted(t_stack *stack_a)
{
	if (!stack_a)
		return (1);
	while (stack_a && stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int valid_list(t_stack *stack_a)
{
	if (is_duplicate(stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		free_list(stack_a);
		return (0);
	}
	if (is_sorted(stack_a))
	{
		free_list(stack_a);
		return (0);
	}
	return (1);
}
