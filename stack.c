#include "push_swap.h"
#include "libft.h"

t_stack *new_node(int content)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->previous = NULL;
	node->pos = 0;
	node->target_pos = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	return (node);
}

void add_node_end(t_stack **stack_a, t_stack *new_node)
{
	t_stack *temp;

	if (!*stack_a)
	{
		*stack_a = new_node;
		return;
	}
	temp = *stack_a;
	while (temp->next)
		temp = temp->next;
	if (new_node)
	{
		temp->next = new_node;
		new_node->previous = temp;
	}
}

t_stack *last_node(t_stack **stack_a)
{
	t_stack *temp;

	if (!*stack_a)
		return (NULL);
	temp = *stack_a;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

int list_size(t_stack **stack_a)
{
	t_stack *temp;
	int count;

	count = 0;
	if (!*stack_a)
		return (0);
	temp = *stack_a;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}
