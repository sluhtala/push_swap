#include "push_swap.h"

int		check_valid_command(char *buf)
{
	if (buf[0] == 's')
	{
		if ((buf[1] == 'a' || buf[1] == 'b' || buf[1] == 's') && buf[2] == '\0')
			return (1);
	}
	if (buf[0] == 'p')
	{
		if ((buf[1] == 'a' || buf[1] == 'b' || buf[1] == 's') && buf[2] == '\0')
			return (1);
	}
	if (buf[0] == 'r')
	{
		if ((buf[1] == 'a' || buf[1] == 'b' || buf[1] == 'r') && buf[2] == '\0')
			return (1);
		if (buf[1] == 'r')
		{
			if ((buf[2] == 'a' || buf[2] == 'b' || buf[2] == 'r') && buf[3] == '\0')
				return (1);
		}
	}
	if (buf[0] == '\n')
		return (1);
	return (0);
}

int		get_command_number(char *buf)
{
	if (!ft_strcmp(buf, "sa"))
		return (SA);
	if (!ft_strcmp(buf, "sb"))
		return (SB);
	if (!ft_strcmp(buf, "ss"))
		return (SS);
	if (!ft_strcmp(buf, "pa"))
		return (PA);
	if (!ft_strcmp(buf, "pb"))
		return (PB);
	if (!ft_strcmp(buf, "ra"))
		return (RA);
	if (!ft_strcmp(buf, "rb"))
		return (RB);
	if (!ft_strcmp(buf, "rr"))
		return (RR);
	if (!ft_strcmp(buf, "rra"))
		return (RRA);
	if (!ft_strcmp(buf, "rrb"))
		return (RRB);
	if (!ft_strcmp(buf, "rrr"))
		return (RRR);
	return (0);
}

int		save_command(t_commands *coms, char *buf)
{
	int i;
	int *temp;

	i = 0;
	if (check_valid_command(buf) == 0)
		return (0);
	if (!buf)
		coms->coms = (int*)malloc(sizeof(int));
	coms->amount++;
	temp = coms->coms;
	coms->coms = (int*)malloc(sizeof(int) * coms->amount);
	while (i < coms->amount - 1)
	{
		coms->coms[i] = temp[i];
		i++;
	}
	free(temp);
	coms->coms[i] = get_command_number(buf);
	return (coms->coms[i]);
}

void	update_print_stacks(t_stacks *s)
{
		ft_printf("\033[A");
		ft_printf("\33[2K");
		ft_printf("\033[A");
		ft_printf("\33[2K");
		ft_printf("\033[A");
		ft_printf("\33[2K");
		ft_printf("\ra: ");
		print_stack(s->a);
		ft_printf("\rb: ");
		print_stack(s->b);
}

t_commands type_commands(t_stacks *s)
{
	t_commands	coms;
	char		buf[11];
	int			r;

	coms.amount = 0;
	coms.coms = NULL;
	buf[0] = 0;
	ft_printf("a: ");
	print_stack(s->a);
	ft_printf("b: ");
	print_stack(s->b);
	while (buf[0] != '\n')
	{
		r = read(2, buf, 10);
		if (buf[0] == '\n' || buf[0] == '\0')
			break ;
		else
			buf[r - 1] = '\0';
		ps_function(s, save_command(&coms, buf));
		update_print_stacks(s);
	}
	return (coms);
}
