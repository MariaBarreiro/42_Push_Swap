/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:57:49 by mda-enca          #+#    #+#             */
/*   Updated: 2025/08/17 18:14:12 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_min(t_list	*stack_a, t_list *stack_b)
{
	size_t	i;
	int		min;

	i = 0;
	min = stack_a->value[0];
	while (i < stack_a->size)
	{
		if (min > stack_a->value[i])
		{
			min = stack_a->value[i];
			stack_a->min_index = i;
		}
		i++;
	}
	
	while (stack_a->value[0] != min)
	{
		if (stack_a->min_index > 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	move_max(t_list	*stack_a, t_list *stack_b)
{
	size_t	i;
	int		max;

	i = 0;
	max = stack_a->value[0];
	while (i < stack_a->size)
	{
		if (max < stack_a->value[i])
		{
			max = stack_a->value[i];
			stack_a->max_index = i;
		}
		i++;
	}
	
	while (stack_a->value[0] != max)
	{
		if (stack_a->max_index > 3)
			rra(stack_a);
		else
			ra(stack_a);
	}
	pb(stack_a, stack_b);
}

int	find_max_bites(int max_index)
{
	int	max;

	max = 0;
	while ((max_index >> max) != 0)
		max++;
	return (max);
}

