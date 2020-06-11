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
