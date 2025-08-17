#ifndef PUSH_SWAP_H
# define    PUSH_SWAP_H

//Includes//

# include	"../Libs/42_Libft/Inc/libft.h"
# include	"../Libs/42_Libft/42_Gnl/get_next_line.h"
# include	"../Libs/42_Libft/42_Ft_Printf/Inc/ft_printf.h"
# include	<fcntl.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdbool.h>
# include	<limits.h>

//Structs//

typedef struct s_list
{
	int		*value;		//array of values
	size_t	size;		// size of stack a with only a few numbers
	size_t	max_size;	//stack a + b / original a
	size_t	min_index;
	size_t	max_index;
} t_list;

typedef struct s_all
{
	t_list	stack_a;
	t_list	stack_b;
} t_all;

//Stack//

bool	start(t_list *stack_a, t_list *stack_b, int ac, char **av);
size_t	count_stack(int ac, char **av);
bool	fill_stack(int ac, char **av, t_list *stack_to_fill);
bool	fill_stack_one(char *arg, t_list *stack_to_fill, size_t *index_x);
bool	check_duplicates(t_list *stack, int result);

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
