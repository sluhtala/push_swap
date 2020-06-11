#include "push_swap.h"

int	check_valid_arg(char *str, int *nums, int len)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
		{
			return (0);
		}
		i++;
	}
	while (j < len)
	{
		if (ft_atoi(str) == nums[j])
			return (0);
		j++;
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
		if (check_valid_arg(args[i], nums, i) == 0)
		{
			error_mgr();
		}
		nums[i] = ft_atoi(args[i]);
		i++; 
	}
	return (nums);
}
