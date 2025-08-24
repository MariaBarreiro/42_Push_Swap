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

void	radix_sort(t_list *stack_a, t_list *stack_b)
{
	int	n_tokens;
	int	max_bites;
	(void)stack_b;

	n_tokens = stack_a->size;
	max_bites = find_max_bites(n_tokens - 1);

}

int	find_max_bites(int max_index)
{
	int	max;

	max = 0;
	while ((max_index >> max) != 0)
		max++;
	return (max);
}
