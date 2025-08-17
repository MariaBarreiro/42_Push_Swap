#include "../../Includes/push_swap.h"

bool	check_ascending(t_list *stack)
{
	size_t	i;

	i = 0;
	if (stack->size == 0)
		return (true);

	while (i < stack->size - 1)
	{
		if (stack->value[i] >= stack->value[i + 1])
			return (true);
		i++;
	}
	return (false);
}

void	sort_solution(t_list *stack_a, t_list *stack_b)
{
	size_t	n_tokens;

	(void)stack_b;
	n_tokens = stack_a->size;
	if (n_tokens == 2)
		sort_two_numbers(stack_a);	
	else if (n_tokens == 3)
		sort_three_numbers(stack_a);	
	else if (n_tokens == 4)
		sort_four_numbers(stack_a, stack_b);	
	else if (n_tokens == 5)
		sort_five_numbers(stack_a, stack_b);	
	// else if (n_tokens > 5)
	// {}

}


