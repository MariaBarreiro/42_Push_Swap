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
} t_list;

typedef struct s_all
{
	t_list	stack_a;
	t_list	stack_b;
} t_all;

//Stack//

int	start(t_list *stack_a, t_list *stack_b, int ac, char **av);
size_t	count_stack(int ac, char **av);
bool	fill_stack(int ac, char **av, t_list *stack_to_fill);
bool	fill_stack_one(char *arg, t_list *stack_to_fill, size_t *index_x);
bool	check_duplicates(t_list *stack, int result);

//Movements//

void	swap(t_list *stack);
void	push(t_list *to, t_list *from);
void	reverse_rotate(t_list *stack);
void	rotate(t_list *stack);

//Utils//

char	*ft_strdup_char(const char *arg, char delimiter);
bool	ft_atoi_modified(const char *str, int *result);


#endif
