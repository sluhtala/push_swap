#include "push_swap.h"

void	reverse_rotate(t_stacks *s, int com)
{
	if ((com == RRR || com == RRA) && s->a_amount > 1)
	{
		if (s->a->previous)
			s->a = s->a->previous;
		else
		{
			while (s->a->next)
				s->a = s->a->next;
		}
		s->a = rearrange(s->a);
	}
	if ((com == RRR || com == RRB) && s->b_amount > 1)
	{
		if (s->b->previous)
			s->b = s->b->previous;
		else
		{
			while (s->b->next)
				s->b = s->b->next;
		}
		s->b = rearrange(s->b);
	}
}

void	rotate(t_stacks *s, int com)
{
	if ((com == RR || com == RA) && s->a_amount > 1)
	{
		if (s->a->next)
			s->a = s->a->next;
		else
		{
			while (s->a->previous)
				s->a = s->a->previous;
		}
		s->a = rearrange(s->a);
	}
	if ((com == RR || com == RB) && s->b_amount > 1)
	{
		if (s->b->next)
			s->b = s->b->next;
		else
		{
			while (s->b->previous)
				s->b = s->b->previous;
		}
		s->b = rearrange(s->b);
	}
	if (com > RR)
		reverse_rotate(s, com);
}

void	push(t_stacks *s, int com)
{
	if (com == PA && s->b_amount >= 1)
	{
		s->a_amount++;	
		s->a = add_top(s->a, s->b->num);
		s->b = delete_node(s->b);
		s->b_amount--;
	}
	if (com == PB && s->a_amount >= 1)
	{
		s->b_amount++;	
		s->b = add_top(s->b, s->a->num);
		s->a = delete_node(s->a);
		s->a_amount--;
	}
}

void	swap(t_stacks *s, int com)
{
	int temp;
	int next;

	if ((com == SS || com == SA) && s->a_amount > 1)
	{
		s->a = rearrange(s->a);
		temp = s->a->num;
		s->a->num = s->a->next->num;
		s->a->next->num = temp;
	}
	if ((com == SS || com == SB) && s->b_amount > 1)
	{
		s->b = rearrange(s->b);
		temp = s->b->num;
		s->b->num = s->b->next->num;
		s->b->next->num = temp;
	}
}

void	ps_function(t_stacks *s, int com)
{
	if (com >= 1 && com <= 3)
		swap(s, com);
	if (com == 4 || com == 5)
		push(s, com);
	if (com >= 6)
		rotate(s, com);
}
