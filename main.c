#include "libft.h"
#include "push_swap.h"

void print_usage(char *str)
{
	ft_printf("Usage: %s <number> <number> ...\n", str);
	exit(0);
}

void error_mgr(void)
{
	ft_putstr_fd("Error\n", 0);
	exit(0);	
}

int	check_valid_arg(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	*get_nums(char **args, int ac)
{
	int *nums;
	int i;

	args++;
	i = 0;
	nums = (int*)malloc(sizeof(int) * ac);
	while (i < ac)
	{
		if (check_valid_arg(args[i]) == 0)
		{
			ft_printf("ERROR\n");
			exit(0);
		}
		nums[i] = ft_atoi(args[i]);
		i++; 
	}
	return (nums);
}

void check_if_sorted(t_stacks *s)
{
	t_stack *tmp;
	tmp = rearrange(s->a);
	while (tmp && tmp->next)
	{
		if (tmp->num > tmp->next->num)
		{
			ft_printf("KO\n");
			return ;
		}
		tmp = tmp->next;
	}
	if (s->b)
	{
		ft_printf("KO\n");
		return ;	
	}
	ft_printf("OK\n");
}


int main(int argc, char **argv)
{
	int			*nums;
	t_commands	coms;
	t_stacks	*stacks;

	if (argc == 1)
		print_usage(argv[0]);
	nums = get_nums(argv, argc - 1);
	stacks = init_stacks(argc - 1, nums);
	check_if_sorted(stacks);
	coms = type_commands(stacks);
	free(nums);
	//for(int i = 0; i < coms.amount; i++)
	//{
	//	ps_function(stacks, coms.coms[i]);
	//}
	check_if_sorted(stacks);
	free(coms.coms);
	return (0);
}
