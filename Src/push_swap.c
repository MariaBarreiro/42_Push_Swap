#include "../Includes/push_swap.h"

// init at NULL;
// handle wrong number of args.
// handle 2 or more args.
// init stack a, put each n in a node, handle signs and duplicates.
// check if stack a is sorted, sort.

int	main (int ac, char **av)
{
	t_all	program;
	
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else if (start(&program.stack_a, &program.stack_b, (ac - 1), &av[1]) == false)
		return (1);
	if (check_ascending(&program.stack_a) == false)
		ft_printf("ERROR NEEDS HANDLING! main!");
	sort_solution(&program.stack_a, &program.stack_b);
}
