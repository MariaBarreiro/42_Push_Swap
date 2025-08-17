/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:37:40 by mda-enca          #+#    #+#             */
/*   Updated: 2025/08/17 13:39:18 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	rra(t_list *stack_a)
{
	if (stack_a && stack_a->size >= 2)
	{
		reverse_rotate (stack_a);
		write (1, "rra\n", 4);
	}
}

void	rrb(t_list *stack_b)
{
	if (stack_b && stack_b->size >= 2)
	{
		reverse_rotate (stack_b);
		write (1, "rrb\n", 4);
	}
}

void	rrr(t_list *stack_a, t_list *stack_b)
{
	if (stack_a && stack_a->size >= 2 && stack_b && stack_b->size >= 2)
	{
		reverse_rotate (stack_a);
		reverse_rotate (stack_b);
		write (1, "rrr\n", 4);
	}
}
