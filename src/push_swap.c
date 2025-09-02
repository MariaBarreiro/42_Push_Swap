/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:30:47 by mda-enca          #+#    #+#             */
/*   Updated: 2025/08/22 13:30:50 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// init at NULL;
// handle wrong number of args.
// handle 2 or more args.
// init stack a, put each n in a node, handle signs and duplicates.
// check if stack a is sorted, sort.

int	main (int ac, char **av)
{
	t_all	program;
	
	if (ac == 1 || (ac == 2 && !av[1][0]))
		ft_printf("ERROR NEEDS HANDLING! main!");
	else if (start(&program.stack_a, &program.stack_b, (ac - 1), &av[1]) == false)
		return (1);
	if (check_ascending(&program.stack_a) == false)
		ft_printf("check_asecending ERROR NEEDS HANDLING! main!");
	sort_solution(&program.stack_a, &program.stack_b);
}
