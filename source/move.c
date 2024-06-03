/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:27:16 by atorma            #+#    #+#             */
/*   Updated: 2024/06/03 15:18:29 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_sa(t_stack *a, int n)
{
	int	top;
	int	tmp;
	if (a->count <= 1)
		return ;

	top = n - a->count;
	tmp = a->arr[top + 1];
	a->arr[top + 1] = a->arr[top];
	a->arr[top] = tmp;

}

void	move_sb(t_stack *b, int n)
{
	move_sa(b, n);
}

void	move_ss(t_stack *a, t_stack *b, int n)
{
	move_sa(a, n);
	move_sb(b, n);
}


int find_top(t_stack *stack, int n)
{
	int i;
	int *arr;

	i = 0;
	arr = stack->arr;
	while (i < n)
	{
		if (arr[i] != -1)
			return (i);
		i++;
	}
	return (-1);
}

void	move_pa(t_stack *a, t_stack *b, int n)
{
	int	b_top;
	int	a_top;

	if (b->count == 0)
		return ;
	b_top = n - b->count;
	a_top = n - a->count - 1;
	a->arr[a_top] = b->arr[b_top];
	b->arr[b_top] = -1;
	a->count++;
	b->count--;
}

void	move_pb(t_stack *a, t_stack *b, int n)
{
	int	b_top;
	int	a_top;

	if (a->count == 0)
		return ;
	b_top = n - b->count - 1;
	a_top = n - a->count;
	b->arr[b_top] = a->arr[a_top];
	a->arr[a_top] = -1;
	b->count++;
	a->count--;
}

void	move_rotate(t_stack *s, int n)
{
	int	top;
	int	last;
	int	tmp;

	if (s->count == 0)
		return ;
	top = n - s->count;
	last = n - 1;
	tmp = s->arr[top];
	ft_memmove(s->arr + top, s->arr + top + 1, (s->count - 1) * sizeof(int));
	s->arr[last] = tmp;
}

void	move_rev_rotate(t_stack *s, int n)
{
	int	top;
	int	last;
	int	tmp;

	if (s->count == 0)
		return ;
	top = n - s->count;
	last = n - 1;
	tmp = s->arr[last];
	ft_memmove(s->arr + top + 1, s->arr + top, (s->count - 1) * sizeof(int));
	s->arr[top] = tmp;
}
