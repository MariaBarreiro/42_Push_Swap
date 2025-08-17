/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:41:01 by mda-enca          #+#    #+#             */
/*   Updated: 2025/08/17 13:44:15 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	sa(t_list *stack_a)
{
	if (stack_a && stack_a->size >= 2)
	{
		swap (stack_a);
		write (1, "sa\n", 3);
	}
}

void	sb(t_list *stack_b)
{
	if (stack_b && stack_b->size >= 2)
	{
		swap (stack_b);
		write (1, "sb\n", 3);
	}
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	if (stack_a && stack_a->size >= 2 && stack_b && stack_b->size >= 2)
	{
		swap (stack_a);
		swap (stack_b);
		write (1, "ss\n", 3);
	}
}
