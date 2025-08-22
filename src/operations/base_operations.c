/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:37:34 by mda-enca          #+#    #+#             */
/*   Updated: 2025/08/17 13:38:11 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_list *stack)
{
	int	temp;

	temp = 0;
	if (stack->size > 1)
	{
		temp = stack->value[0];
		stack->value[0] = stack->value[1];
		stack->value[1] = temp;
	}
}

void	push(t_list *to, t_list *from)
{
	to->size += 1;
	reverse_rotate(to);
	to->value[0] = from->value[0];
	rotate(from);
	from->size -= 1;
}

void	reverse_rotate(t_list *stack)
{
	size_t	i;
	int		temp;

	temp = 0;
	if (stack->size > 1)
	{
		temp = stack->value[stack->size - 1];
		i = stack->size - 1;
		while (i > 0)
		{
			stack->value[i] = stack->value[i - 1];
			i--;
		}
	}
	stack->value[0] = temp;
}

void	rotate(t_list *stack)
{
	size_t	i;
	int		temp;

	temp = 0;
	if (stack->size > 1)
	{
		i = 0;
		temp = stack->value[0];
		while (i < stack->size - 1)
		{
			stack->value[i] = stack->value[i + 1];
			i++;
		}
		stack->value[stack->size - 1] = temp;
	}
}
