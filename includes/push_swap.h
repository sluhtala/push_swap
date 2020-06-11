#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# define BSIZE 10
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct	s_commands
{
	int *coms;
	int	amount;
}				t_commands;

typedef struct	s_stack
{
	int num;

	struct s_stack *next;
	struct s_stack *previous;
}				t_stack;

typedef struct	s_stacks
{
	t_stack *a;
	t_stack *b;
	int			b_amount;
	int			a_amount;
}				t_stacks;

void		error_mgr(void);
t_commands	type_commands(t_stacks *s);
void		print_stack(t_stack *top);
t_stacks	*init_stacks(int amount, int *nums);
t_stack		*append(t_stack *top, int num);
t_stack		*add_top(t_stack *top, int num);
t_stack		*rearrange(t_stack *top);
t_stack		*delete_node(t_stack *top);
void		ps_function(t_stacks *s, int com);

#endif
