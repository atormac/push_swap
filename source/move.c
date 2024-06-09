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

void	move_push(t_record *r, t_stack *from, t_stack *to, int n)
{
	int	to_top;
	int	from_top;

	if (from->count == 0)
		return ;
	to_top = n - to->count - 1;
	from_top = n - from->count;
	to->arr[to_top] = from->arr[from_top];
	from->arr[from_top] = -1;
	to->count++;
	from->count--;
	if (to->id == STACK_A)
		record_move(r, MV_PA);
	else
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
