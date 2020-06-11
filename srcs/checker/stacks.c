#include "libft.h"
#include "push_swap.h"

void		print_stack(t_stack *top)
{
	t_stack *temp;

	top = rearrange(top);
	temp = top;
	if (!top)
	{
		ft_printf("\n");
		return ;
	}
	while (temp)
	{
		ft_printf("%d ", temp->num);	
		temp = temp->next;
	}
	ft_printf("\n");
}

t_stack		*delete_node(t_stack *top)
{
	t_stack *next;
	t_stack *prev;

	if (!top)
		return (NULL);
	next = top->next;
	prev = top->previous;
	if (prev)
		prev->next = next;
	if (next)
		next->previous = prev;
	free(top);
	return (next);
}

t_stack		*rearrange(t_stack *top)
{
	t_stack *last;
	t_stack *prev;

	if (!top || !top->previous)
		return (top);
	last = top;
	while (last->next)
		last = last->next;
	prev = top->previous;
	prev->next = NULL;
	while (prev->previous)
		prev = prev->previous;
	prev->previous = last;
	last->next = prev;
	top->previous = NULL;
	return (top);	
}

t_stack		*new_node(int num)
{
	t_stack *s;
	
	s = (t_stack*)malloc(sizeof(t_stack));
	s->num = num;
	s->next = NULL;
	s->previous = NULL;
	return (s);
}

t_stack		*add_top(t_stack *top, int num)
{
	t_stack *prev;
	t_stack *new;

	if (!top)
		return (new_node(num));
	prev = top->previous;
	new = new_node(num);
	new->next = top;
	top->previous = new;
	new->previous = prev;
	return (new);	
}

t_stack		*append(t_stack *top, int num)
{
	t_stack *temp;

	if (!top)
		return (new_node(num));
	temp = top;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new_node(num);
	temp->next->previous = temp;
	return (top);
}

t_stacks	*init_stacks(int amount, int *nums)
{
	t_stacks *s;
	int i;

	s = (t_stacks*)malloc(sizeof(t_stacks));
	i = 0;
	s->b = NULL;
	s->a = NULL;
	s->a_amount = amount;
	s->b_amount = 0;
	while (i < amount)
	{
		s->a = append(s->a, nums[i]);
		i++;
	}
	return (s);
}
