/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:59:36 by mda-enca          #+#    #+#             */
/*   Updated: 2025/09/02 16:01:48 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//Includes//

# include "../libs/42_libft/inc/libft.h"
# include "../libs/42_libft/42_gnl/get_next_line.h"
# include "../libs/42_libft/42_ft_printf/inc/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

//Structs//

typedef struct s_list
{
	int		*value;		//array of values
	int		*index;
	size_t	size;		// size of stack a with only a few numbers
	size_t	max_size;	//stack a + b / original a
	size_t	min_index;
	size_t	max_index;
	int		max_value;
}	t_list;

typedef struct s_all
{
	t_list	stack_a;
	t_list	stack_b;
}	t_all;

//Stack//

bool	start(t_list *stack_a, t_list *stack_b, int ac, char **av);
size_t	count_stack(int ac, char **av);
bool	fill_stack(int ac, char **av, t_list *stack_to_fill);
bool	fill_stack_one(char *arg, t_list *stack_to_fill, size_t *index_x);
bool	check_duplicates(t_list *stack, int result);
void	init_index(t_list *stack_a, t_list *stack_b, size_t stack_size);

//Stack Utils//

bool	check_ascending(t_list *stack);
void	sort_solution(t_list *stack_a, t_list *stack_b);

//Sorting//

void	sort_two_numbers(t_list *stack_a);
void	sort_three_numbers(t_list *stack_a);
void	sort_four_numbers(t_list *stack_a, t_list *stack_b);
void	sort_five_numbers(t_list *stack_a, t_list *stack_b);
void	move_min(t_list	*stack_a, t_list *stack_b);
void	move_max(t_list	*stack_a, t_list *stack_b);
void	radix_sort(t_list *stack_a, t_list *stack_b);
int		find_max_bits(t_list *stack_a);
void	order_stack(t_list *stack_a);

void	print_stack(t_list *stack);

//Operations//

void	swap(t_list *stack);
void	push(t_list *to, t_list *from);
void	reverse_rotate(t_list *stack);
void	rotate(t_list *stack);
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
void	pa(t_list *stack_a, t_list *stack_b);
void	pb(t_list *stack_a, t_list *stack_b);
void	ra(t_list *stack_a);
void	rb(t_list *stack_b);
void	rr(t_list *stack_a, t_list *stack_b);
void	rrb(t_list *stack_b);
void	rra(t_list *stack_a);
void	rrr(t_list *stack_a, t_list *stack_b);

//Utils//

char	*ft_strdup_char(const char *arg, char delimiter);
bool	ft_atoi_modified(const char *str, int *result);
#endif
