int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char			**split;
	char			**args;
	int				is_split;

	a = NULL;
	b = NULL;
	split = NULL;
	is_split = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		args = split;
		is_split = 1;
	}
	else
		args = argv + 1;
	init_stack_a(&a, args, is_split);
	parser(a, b);
	free_stack(&a);
	if (split)
		free_argv(split);
}
