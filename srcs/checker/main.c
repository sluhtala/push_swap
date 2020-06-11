#include "libft.h"
#include "push_swap.h"


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
	check_if_sorted(stacks);
	free(coms.coms);
	return (0);
}
