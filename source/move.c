/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:27:16 by atorma            #+#    #+#             */
/*   Updated: 2024/06/03 19:47:38 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_swap(t_record *r, t_stack *a, int n)
{
	int	top;
	int	tmp;
	if (a->count <= 1)
		return ;

	top = n - a->count;
	tmp = a->arr[top + 1];
	a->arr[top + 1] = a->arr[top];
	a->arr[top] = tmp;
	if (a->id == STACK_A)
		record_move(r, MV_SA);
	else
		record_move(r, MV_SB);
}

void	move_pa(t_record *r, t_stack *a, t_stack *b, int n)
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
	record_move(r, MV_PA);
}

void	move_pb(t_record *r, t_stack *a, t_stack *b, int n)
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
	record_move(r, MV_PB);
}

void	move_rotate(t_record *r, t_stack *s, int n)
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
	if (s->id == STACK_A)
		record_move(r, MV_RA);
	else
		record_move(r, MV_RB);
}

void	move_rev_rotate(t_record *r, t_stack *s, int n)
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
	if (s->id == STACK_A)
		record_move(r, MV_RRA);
	else
		record_move(r, MV_RRB);
}
