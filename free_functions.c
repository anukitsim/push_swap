#include "push_swap.h"

void free_list(t_stack *stack_a)
{
	t_stack *second;

	if (stack_a)
	{
		second = stack_a->next;
	}
	else
		return;
	while (second != NULL)
	{
		free(stack_a);
		stack_a = second;
		second = second->next;
	}
	free(stack_a);
}

void free_array(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
