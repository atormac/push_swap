/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:16:09 by atorma            #+#    #+#             */
/*   Updated: 2024/06/06 15:33:25 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	get_min_dist(int *arr, int count)
{
	int i = 0;
	int	min;
	int	min_index;

	min = arr[0];
	min_index = 0;
	while (i < count)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	get_max_dist(int *arr, int count)
{
	int i = 0;
	int	max;
	int	max_index;

	max = arr[0];
	max_index = 0;
	while (i < count)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

void	sort_three(t_record *r, t_stack *s, int n)
{
	int	*top_stack;
	int	greatest;
	int	smallest;

	top_stack = s->arr + n - s->count;
	greatest = get_max_dist(top_stack, s->count);
	smallest = get_min_dist(top_stack, s->count);
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
