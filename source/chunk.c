/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:14:39 by atorma            #+#    #+#             */
/*   Updated: 2024/06/10 15:15:27 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_rotate_top(t_record *r, t_stack *a, int n, int low, int high)
{
	int	top;
	int	mv_count_top;
	int	mv_count_bottom;

	top = a->arr[n - a->count];
	mv_count_top = cost_top(a, n, low, high);
	mv_count_bottom = cost_down(a, n, low, high);
	while (1)
	{
		if (top >= low && top <= high)
			break ;
		if (mv_count_bottom < mv_count_top)
			move_rev_rotate(r, a, n);
		else
			move_rotate(r, a, n);
		top = a->arr[n - a->count];
	}
}

void	chunk_push_back(t_record *r, t_stack *a, t_stack *b, int n)
{
	int	i;
	int	high;
	int	low;

	while (b->count > 1)
	{
		high = b->count - 1;
		low = b->count - 2;
		i = 2;
		while (i--)
		{
			chunk_rotate_top(r, b, n, low, high);
			move_push(r, b, a, n);
		}
		if (a->arr[n - a->count] > a->arr[n - a->count + 1])
			move_swap(r, a, n);
	}
	if (b->count > 0)
	{
		move_push(r, b, a, n);
		if (a->arr[n - a->count] > a->arr[n - a->count + 1])
			move_swap(r, a, n);
	}
}

void	chunk_push(t_record *r, t_stacks *stacks, int chunk_count, int chunk_size)
{
	int	i;
	int	low;
	int	high;
	int	median;

	while (chunk_count > 0)
	{
		low = stacks->b->count;
		if (chunk_count == 1)
			chunk_size += stacks->size % chunk_size;
		i = chunk_size;
		while (stacks->a->count > 3 && i-- > 0)
		{
			median = low + (chunk_size / 2);
			high = low + chunk_size - 1;
			if (chunk_count == 1)
				high -= 3;
			chunk_rotate_top(r, stacks->a, stacks->size, low, high);
			move_push(r, stacks->a, stacks->b, stacks->size);
			if (stacks->b->arr[stacks->size - stacks->b->count] < median)
				move_rotate(r, stacks->b, stacks->size);
		}
		chunk_count--;
	}
}
