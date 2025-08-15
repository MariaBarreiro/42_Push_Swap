#include "../Includes/push_swap.h"

// init at NULL;
// handle wrong number of args.
// handle 2 or more args.
// init stack a, put each n in a node, handle signs and duplicates.
// check if stack a is sorted, sort.

int	main (int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;

	if (ac == 2 || ac == 2 && !av[1][0])
		return (0);
	else if (ac == 2)
		av = ft_split(av[1], " ");

	init_a_stack()
}
