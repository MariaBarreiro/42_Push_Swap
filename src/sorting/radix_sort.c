/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:59:28 by mda-enca          #+#    #+#             */
/*   Updated: 2025/09/02 16:53:52 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	radix_sort(t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	j;
	int	n_tokens;
	int	max_bits;

	i = 0;
	n_tokens = stack_a->size;
	order_stack(stack_a);
	max_bits = find_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		order_stack(stack_a);
		while (j < n_tokens)
		{
			if ((stack_a->index[j] >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		i++;
	}
}

void	order_stack(t_list *stack_a)
{
	size_t	new_index;
	size_t	min_pos;
	size_t	k;
	int		min_value;

	new_index = 0;
	min_pos = stack_a->size;
	k = 0;
	min_value = 0;
	check_and_init(stack_a);
	while (new_index < stack_a->size)
	{
		first_loop(stack_a, &min_pos, &min_value);
		if (min_pos == stack_a->size)
			break ;
		second_loop(stack_a, &min_pos, &min_value);
		stack_a->index[min_pos] = new_index;
		new_index++;
	}
	stack_a->min_index = 0;
	if (stack_a->size > 0)
		stack_a->max_index = stack_a->size - 1;
	else
		stack_a->max_index = 0;
}

void	check_and_init(t_list *stack_a)
{
	size_t	i;

	i = 0;
	if (!stack_a || !stack_a->value || !stack_a->index || stack_a->size == 0)
		ft_printf("error needs handling! order_stack!");
	while (i < stack_a->size)
	{
		stack_a->index[i] = -1;
		i++;
	}
}

void	first_loop(t_list *stack_a, size_t *min_pos, int *min_value)
{
	size_t	i;

	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->index[i] == -1)
		{
			*min_pos = i;
			*min_value = stack_a->value[i];
			break ;
		}
		i++;
	}
}

void	second_loop(t_list *stack_a, size_t *min_pos, int *min_value)
{
	size_t	k;

	k = *min_pos + 1;
	while (k < stack_a->size)
	{
		if (stack_a->index[k] == -1 && stack_a->value[k] < *min_value)
		{
			*min_value = stack_a->value[k];
			*min_pos = k;
		}
		k++;
	}
}
