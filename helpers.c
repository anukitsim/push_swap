#include "push_swap.h"
#include "libft.h"

long ft_atol(const char *nptr)
{
	long i;
	long sign;
	long result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

static int arr_to_node(char **arr, t_stack **stack_a)
{
	int i;

	i = 0;
	while (arr[i])
	{
		if (valid_node(&arr[i], stack_a))
			i++;
		else
			return (0);
	}
	return (1);
}

static int	handle_split_string(t_stack **stack_a, char *s)
{
	char **arr_of_nums;

	arr_of_nums = ft_split(s, ' ');
	if (!arr_of_nums)
	{
		free_list(*stack_a);
		return (0);
	}
	if (!arr_of_nums[0])
	{
		free_array(arr_of_nums);
		free_list(*stack_a);
		return (0);
	}
	if (!arr_to_node(arr_of_nums, stack_a))
	{
		free_array(arr_of_nums);
		free_list(*stack_a);
		return (0);
	}
	free_array(arr_of_nums);
	return (1);
}

int handle_string(t_stack **stack_a, char *s)
{
	if (!ft_strchr(s, ' '))
	{
		if (!valid_node(&s, stack_a))
		{
			free_list(*stack_a);
			return (0);
		}
		return (1);
	}
	return (handle_split_string(stack_a, s));
}