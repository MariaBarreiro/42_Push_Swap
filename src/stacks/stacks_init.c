/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:34:20 by mda-enca          #+#    #+#             */
/*   Updated: 2025/09/02 16:27:14 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	start(t_all *program, int ac, char **av)
{
	size_t	stack_size;	

	stack_size = count_stack(ac, av);
	program->stack_a.value = (int *)malloc(stack_size * sizeof(int));
	if (!program->stack_a.value)
		die (program, 1);
	program->stack_b.value = (int *)malloc(stack_size * sizeof(int));
	if (!program->stack_b.value)
		die (program, 1);
	program->stack_a.index = (int *)malloc(stack_size * sizeof(int));
	if (!program->stack_a.index)
		die (program, 1);
	program->stack_b.index = (int *)malloc(stack_size * sizeof(int));
	if (!program->stack_b.index)
		die (program, 1);
	init_index(&program->stack_a, &program->stack_b, stack_size);
	if (fill_stack(ac, av, &program->stack_a) == false)
		die (program, 1);
	return (true);
}

size_t	count_stack(int ac, char **av)
{
	size_t	size;
	size_t	x;
	size_t	y;

	size = 0;
	y = 0;
	while (y < (size_t)ac)
	{
		x = 0;
		check_null(av, &y, &x);
		while (av[y][x])
		{
			while (av[y][x] == ' ' && av[y][x])
				x++;
			if (!av[y][x])
				check_null(av, &y, &x);
			size++;
			while (av[y][x] && av[y][x] != ' ')
				x++;
		}
		y++;
	}
	if (!size)
		exit (1);
	return (size);
}

bool	fill_stack(int ac, char **av, t_list *stack_to_fill)
{
	size_t	x;
	size_t	y;
	char	*arg;

	x = 0;
	y = 0;
	while (y < (size_t)ac)
	{
		arg = av[y];
		if (fill_stack_one(arg, stack_to_fill, &x) == false)
			return (false);
		y++;
	}
	return (true);
}

bool	fill_stack_one(char *arg, t_list *stack_to_fill, size_t *index_x)
{
	char	*str;
	int		result;

	while (*arg)
	{
		while (*arg && *arg == ' ')
			arg++;
		if (!*arg)
			break ;
		str = ft_strdup_char(arg, ' ');
		if (ft_atoi_modified(str, &result) == false)
			return (error_handling_fill_stack(str));
		if (check_duplicates(stack_to_fill, result) == true)
			return (error_handling_fill_stack(str));
		stack_to_fill->value[*index_x] = result;
		*index_x += 1;
		stack_to_fill->size += 1;
		while (*arg && *arg != ' ')
			arg++;
		free (str);
	}
	return (true);
}

bool	check_duplicates(t_list *stack, int result)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->value[i] == result)
			return (true);
		i++;
	}
	return (false);
}
