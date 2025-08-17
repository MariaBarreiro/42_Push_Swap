/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:29:08 by mda-enca          #+#    #+#             */
/*   Updated: 2025/08/17 13:36:18 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	ra(t_list *stack_a)
{
	if (stack_a && stack_a->size >= 2)
	{
		rotate (stack_a);
		write (1, "ra\n", 3);
	}
}

void	rb(t_list *stack_b)
{
	if (stack_b && stack_b->size >= 2)
	{
		rotate (stack_b);
		write (1, "rb\n", 3);
	}
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	if (stack_a && stack_a->size >= 2 && stack_b && stack_b->size >= 2)
	{
		rotate (stack_a);
		rotate (stack_b);
		write (1, "rr\n", 3);
	}
}
