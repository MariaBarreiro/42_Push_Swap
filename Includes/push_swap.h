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

typedef struct s_node
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct	s_node	*target;
	struct	s_node	*next;
	struct	s_node	*prev;
} t_node;

#endif
