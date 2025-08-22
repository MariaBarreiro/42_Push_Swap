/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:46:18 by mda-enca          #+#    #+#             */
/*   Updated: 2025/08/17 13:52:12 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_list *stack_a, t_list *stack_b)
{
	if (stack_b && stack_b->size > 0)
	{
		push (stack_a, stack_b);
		write (1, "pa\n", 3);
	}
}

void	pb(t_list *stack_a, t_list *stack_b)
{
	if (stack_a && stack_a->size > 0)
	{
		push (stack_b, stack_a);
		write (1, "pb\n", 3);
	}
}
