/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:39:57 by mda-enca          #+#    #+#             */
/*   Updated: 2025/08/17 14:11:33 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_two_numbers(t_list *stack_a)
{
	if (stack_a->value[0] > stack_a->value[1])
		sa(stack_a);
}

void	sort_three_numbers(t_list *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->value[0];
	second = stack_a->value[1];
	third = stack_a->value[2];

	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && first > third && second < third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
	//
	// if (first >= second + third && first  > second && second < third)
	// 	ra(stack_a);
	// else if (first  > second && second < third)
	// 	sa(stack_a);
	// else if (first > third && first < second && second > third)
	// 	rra(stack_a);
	// else if (first < third && first < second && second > third)
	// {
	// 	sa(stack_a);
	// 	ra(stack_a);
	// }
	// else if (first > second && second > third)
	// {
	// 	ra(stack_a);
	// 	sa(stack_a);
	// }
}

void	sort_four_numbers(t_list *stack_a, t_list *stack_b)
{
	move_min(stack_a, stack_b);
	sort_three_numbers(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five_numbers(t_list *stack_a, t_list *stack_b)
{
	move_max(stack_a, stack_b);
	sort_four_numbers(stack_a, stack_b);
	pa(stack_a, stack_b);
	ra(stack_a);
}
