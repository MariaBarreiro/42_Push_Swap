/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 10:35:21 by mda-enca          #+#    #+#             */
/*   Updated: 2025/09/03 12:30:55 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	die(t_all *program, int	type_exit)
{
	if (program->stack_a.value)
		free(program->stack_a.value);
	if (program->stack_b.value)
		free(program->stack_b.value);
	if (program->stack_a.index)
		free(program->stack_a.index);
	if (program->stack_b.index)
		free(program->stack_b.index);
	if (type_exit == 0)
		exit (0);
	else if (type_exit == 1)
		exit (1);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	free_stack(t_list *stack)
{
	free(stack->value);
	free(stack->index);
}

void	free_program(t_all *program)
{
	free(program->stack_a.value);
	free(program->stack_b.value);
	free(program->stack_a.index);
	free(program->stack_b.index);
}

