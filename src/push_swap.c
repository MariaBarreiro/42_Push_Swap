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
		return (0);
	else if (start(&program, (ac - 1), &av[1]) == false)
	{
		die(&program, 1);
		return (1);
	}
	if (check_ascending(&program.stack_a) == false)
	{
		die(&program, 0);
		exit (0);
	}
	sort_solution(&program.stack_a, &program.stack_b);
	die(&program, 0);
}
