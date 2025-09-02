/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:34:20 by mda-enca          #+#    #+#             */
/*   Updated: 2025/08/22 13:30:38 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	start(t_list *stack_a, t_list *stack_b, int ac, char **av)
{
	size_t	stack_size;	

	stack_size = count_stack(ac, av);
	
	stack_a->value = (int *)malloc(stack_size * sizeof(int));
	if (!stack_a->value)
		ft_printf("Malloc wrong! \n NEED TO HANDLE IT");
	stack_b->value = (int *)malloc(stack_size * sizeof(int));
	if (!stack_b->value)
		ft_printf("Malloc wrong! \n NEED TO HANDLE IT");

	stack_a->index = (int *)malloc(stack_size * sizeof(int));
	if (!stack_a->index)
		ft_printf("Malloc wrong! \n NEED TO HANDLE IT");
	stack_b->index = (int *)malloc(stack_size * sizeof(int));
	if (!stack_b->index)
		ft_printf("Malloc wrong! \n NEED TO HANDLE IT");

	init_index(stack_a, stack_b, stack_size);
	if (fill_stack(ac, av, stack_a) == false)
		ft_printf("NEED TO HANDLE IT! start!");
	return (true);
}

size_t	count_stack(int ac, char **av)
{
	size_t	size;
	size_t	x;
	size_t	y;

	size = 0;
	y = 0;
	x = 0;
	
	while (y < (size_t)ac)
	{
		x = 0;
		while (av[y][x])
		{
			while (av[y][x] == ' ' && av[y][x])
				x++;

			if (!av[y][x])
				break ;

			size++;

			while (av[y][x] && av[y][x] != ' ')
				x++;
		}
		y++;
	}

	// while (y < (size_t)ac && av[y][x])
	// {
	// 	while (av[y][x])
	// 	{
	// 		if (av[y][x] != ' ' && av[y][x])
	// 			size++;
	// 		else if (!av[y][x])
	// 			break ;
	// 		x++;
	// 	}
	// 	x = 0;
	// 	y++;
	// }
	if (!size)
		ft_printf("Wasn't able to count stack!\n NEED TO HANDLE IT");
	return (size);
}

bool	fill_stack(int ac, char **av, t_list *stack_to_fill)
{
	size_t	x;
	size_t	y;
	char	*arg;

	x = 0;
	y = 0;
	while (y <(size_t)ac)
	{
		arg = av[y];
		if (fill_stack_one(arg, stack_to_fill, &x) == false)
			ft_printf("ERROR NEEDS HANDLING! fill_stack!");
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
			break;

		str = ft_strdup_char(arg, ' ');
		if (ft_atoi_modified(str, &result) == false)
			ft_printf("NEEDS HANDLING! fill_stack_one!");
		if (check_duplicates(stack_to_fill, result) == true)
			ft_printf("NEEDS HANDLING! fill_stack_one!");

		stack_to_fill->value[*index_x] = result;
		*index_x += 1;
		stack_to_fill->size += 1;

		while (*arg && *arg != ' ')
			arg++;
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
