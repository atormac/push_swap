/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:16:09 by atorma            #+#    #+#             */
/*   Updated: 2024/06/10 18:08:08 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_array(int *tab, int size)
{
	int		tmp;
	int		x;
	int		i;

	i = 0;
	while (i < size)
	{
		x = i + 1;
		while (x < size)
		{
			if (tab[i] > tab[x])
			{
				tmp = tab[i];
				tab[i] = tab[x];
				tab[x] = tmp;
			}
			x++;
		}
		i++;
	}
}

void	sort_three(t_record *r, t_stack *s, int n)
{
	int	*top_stack;
	int	greatest;
	int	smallest;

	top_stack = s->arr + n - s->count;
	greatest = cost_max(top_stack, s->count);
	smallest = cost_min(top_stack, s->count);
	if (greatest == 2)
		move_swap(r, s, n);
	else if (greatest == 0 && smallest == 2)
	{
		move_swap(r, s, n);
		move_rev_rotate(r, s, n);
	}
	else if (greatest == 1 && smallest == 0)
	{
		move_swap(r, s, n);
		move_rotate(r, s, n);
	}
	else if (greatest == 0 && smallest == 1)
		move_rotate(r, s, n);
	else if (greatest == 1 && smallest == 2)
		move_rev_rotate(r, s, n);
}

void	sort_chunked(t_record *r, t_stacks *stacks)
{
	int	chunk_size;
	int	chunk_count;

	chunk_size = stacks->size / CHUNK_COUNT;
	if (stacks->size >= 150)
		chunk_size = 50;
	if (chunk_size == 0)
		chunk_size = 1;
	chunk_count = stacks->size / chunk_size;
	chunk_push(r, stacks, chunk_count, chunk_size);
	if (!array_is_sorted(stacks->a->arr, stacks->size))
		sort_three(r, stacks->a, stacks->size);
	chunk_push_back(r, stacks->a, stacks->b, stacks->size);
}

void	sort_stack(t_record *r, t_stacks *stacks)
{
	if (stacks->size == 2)
		move_swap(r, stacks->a, stacks->size);
	else if (stacks->size == 3)
		sort_three(r, stacks->a, stacks->size);
	else
		sort_chunked(r, stacks);
	if (!r->str)
		return ;
	ft_putstr_fd(r->str, 1);
	free(r->str);
}
