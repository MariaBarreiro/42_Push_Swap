/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:59:28 by mda-enca          #+#    #+#             */
/*   Updated: 2025/08/22 15:59:32 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

void	radix_sort(t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	j;
	int	n_tokens;
	int	max_bits;

	i = 0;
	j = 0;
	n_tokens = stack_a->size;
//	print_stack(stack_a);
	order_stack(stack_a);
	max_bits = find_max_bits(stack_a);
//	printf("max_bits:%i\n", max_bits);
//	print_stack(stack_a);
	while (i < max_bits) //loop over each bit position
	{
		j = 0;
		order_stack(stack_a);
		while (j < n_tokens) //process every element in stack a
		{
			// printf("index[0]: %i\n", stack_a->index[j]);
			if((stack_a->index[j] >> i) & 1) //look at the bit i of the TOP element
				ra(stack_a); //equals to one. keep in stack a and rotate
			else
				pb(stack_a, stack_b); //send to stack b
			j++;
		}
		while (stack_b->size > 0) //bring everything back to stack a
			pa(stack_a, stack_b);
		i++;
	}
//print_stack(stack_a);
}
void	print_stack(t_list *stack)
{
	size_t i = 0;

	printf("STACK (size = %zu):\n", stack->size);
	while (i < stack->size)
	{
		printf("pos %zu: value=%d, index=%d\n", 
		          i, stack->value[i], stack->index[i]);
		i++;
	}
}
void	order_stack(t_list *stack_a)
{
	size_t	new_index;
	size_t	min_pos;
	size_t	i;
	size_t	k;
	int		min_value;

	new_index = 0;
	min_pos = stack_a->size;
	i = 0;
	k = 0;
	min_value = 0;
	
	if (!stack_a || !stack_a->value || !stack_a->index || stack_a->size == 0)
		ft_printf("error needs handling! order_stack!");

//	printf("%zu, %zu", i, stack_a->size);	
	while (i < stack_a->size)
	{
		stack_a->index[i] = -1;
		i++;
	}

//	print_stack(stack_a);	
	while (new_index < stack_a->size)
	{	
		i = 0;
		min_pos = stack_a->size;
		
		while (i < stack_a->size) //find first unassigned position
		{
			if (stack_a->index[i] == -1)
			{
				min_pos = i;
				min_value = stack_a->value[i];
				break;
			}
			i++;
		}	
		if (min_pos == stack_a->size)
			break; //nothing left to assign
		
		k = min_pos + 1;
		while (k < stack_a->size)
		{
			if (stack_a->index[k] == -1 && stack_a->value[k] < min_value)
			{
				min_value = stack_a->value[k];
				min_pos = k;
			}
			k++;
		}
		stack_a->index[min_pos] = new_index;
		new_index++;
	}
	stack_a->min_index = 0;
	stack_a->max_index = (stack_a->size > 0) ? (stack_a->size - 1) : 0;
}
