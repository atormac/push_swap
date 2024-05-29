/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:27:16 by atorma            #+#    #+#             */
/*   Updated: 2024/05/29 20:06:04 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_sa(t_stack *a)
{
	int	tmp;
	if (a->count <= 1)
		return ;
	tmp = a->arr[1];
	a->arr[1] = a->arr[0];
	a->arr[0] = tmp;

}

void	move_sb(t_stack *b)
{
	move_sa(b);
}

void	move_ss(t_stack *a, t_stack *b)
{
	move_sa(a);
	move_sb(b);
}

void	move_pa(t_stack *a, t_stack *b)
{
	if (b->count == 0)
		return ;
	a->arr[0] = b->arr[0];
	b->count--;
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

void	move_pb(t_stack *a, t_stack *b, int n)
{
	int i;

	if (a->count == 0)
		return ;
	i = find_top(a, n);
	b->arr[i] = a->arr[i];
	a->arr[0] = -1;
	b->count++;
}
