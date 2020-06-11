#include "push_swap.h"

void	print_comm(int coms)
{
	if (coms[i] == SA)
		ft_printf("sa\n");
	if (coms[i] == SB)
		ft_printf("sb\n");
	if (coms[i] == SS)
		ft_printf("ss\n");
	if (coms[i] == PA)
		ft_printf("pa\n");
	if (coms[i] == PB)
		ft_printf("pb\n");
	if (coms[i] == RA)
		ft_printf("ra\n");
	if (coms[i] == RB)
		ft_printf("rb\n");
	if (coms[i] == RR)
		ft_printf("rr\n");
	if (coms[i] == RRA)
		ft_printf("rr\n");
	if (coms[i] == RRB)
		ft_printf("rr\n");
	if (coms[i] == RRR)
		ft_printf("rr\n");
}

void	print_commands(int *coms)
{
	int i;

	i = 0;
	while (coms[i] != 0)
	{
		print_comm(coms[i]);
		i++;
	}
}

int *get_commands(int *nums, int len)
{
	int *commands;

	
}

int		main(int argc, char **argv)
{
	int *nums;
	int *commands;

	if (argc == 1)
		print_usage();
	nums = get_nums(argv, argc - 1);
	commands = get_commands(nums, argc - 1);
	print_commands(commands);
	free(commands);
	return (0);
}
