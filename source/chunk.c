/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:14:39 by atorma            #+#    #+#             */
/*   Updated: 2024/06/10 16:13:54 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_rotate_top(t_record *r, t_stack *s, int size, t_chunk *chunk)
{
	int	top;
	int	moves_top;
	int	moves_down;

	top = s->arr[size - s->count];
	moves_top = cost_top(s, size, chunk->low, chunk->high);
	moves_down = cost_down(s, size, chunk->low, chunk->high);
	while (1)
	{
		if (top >= chunk->low && top <= chunk->high)
			break ;
		if (moves_down < moves_top)
			move_rev_rotate(r, s, size);
		else
			move_rotate(r, s, size);
		top = s->arr[size - s->count];
	}
}

void	chunk_push_back(t_record *r, t_stack *a, t_stack *b, int n)
{
	t_chunk	chunk;
	int		i;

	while (b->count > 1)
	{
		chunk.high = b->count - 1;
		chunk.low = b->count - 2;
		i = 2;
		while (i--)
		{
			chunk_rotate_top(r, b, n, &chunk);
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

void	chunk_push(t_record *r, t_stacks *stacks, int chunk_cnt, int chunk_sz)
{
	t_chunk	chunk;
	int		i;
	int		median;

	while (chunk_cnt > 0)
	{
		chunk.low = stacks->b->count;
		if (chunk_cnt == 1)
			chunk_sz += stacks->size % chunk_sz;
		i = chunk_sz;
		while (stacks->a->count > 3 && i-- > 0)
		{
			median = chunk.low + (chunk_sz / 2);
			chunk.high = chunk.low + chunk_sz - 1;
			if (chunk_cnt == 1)
				chunk.high -= 3;
			chunk_rotate_top(r, stacks->a, stacks->size, &chunk);
			move_push(r, stacks->a, stacks->b, stacks->size);
			if (stacks->b->arr[stacks->size - stacks->b->count] < median)
				move_rotate(r, stacks->b, stacks->size);
		}
		chunk_cnt--;
	}
}
