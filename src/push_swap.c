/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:55:18 by mda-enca          #+#    #+#             */
/*   Updated: 2025/09/02 16:56:00 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_all	program;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		ft_printf("ERROR NEEDS HANDLING! main!");
	else if (start(&program.stack_a, &program.stack_b, (ac - 1),
			&av[1]) == false)
		return (1);
	if (check_ascending(&program.stack_a) == false)
		ft_printf("check_asecending ERROR NEEDS HANDLING! main!");
	sort_solution(&program.stack_a, &program.stack_b);
}
