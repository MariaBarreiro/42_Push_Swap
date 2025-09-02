/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:30:30 by mda-enca          #+#    #+#             */
/*   Updated: 2025/08/22 13:30:33 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_index(t_list *stack_a, t_list *stack_b, size_t stack_size)
{
	size_t	i;

	i = 0;

	stack_a->max_size = stack_size;
	stack_b->max_size = stack_size;
	stack_a->size = 0;
	stack_b->size = 0;

	while (i < stack_size)
	{
		stack_a->index[i] = -1;
		stack_b->index[i] = -1;
		i++;
	}
}

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
	else if (n_tokens > 5)
		radix_sort(stack_a, stack_b);
}


