/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:12:41 by atorma            #+#    #+#             */
/*   Updated: 2024/06/06 15:48:55 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


void	rotate_in_range(t_record *r, t_stack *a, int n, int low, int high)
{
	int	mv_count_top;
	int	mv_count_bottom;

	mv_count_top = cost_top(a, n, low, high);
	mv_count_bottom = cost_down(a, n, low, high);
	int	top = a->arr[n - a->count];

	while (1)
	{
		if (top >= low && top <= high)
			break;
		if (mv_count_bottom < mv_count_top)
			move_rev_rotate(r, a, n);
		else
			move_rotate(r, a, n);
		top = a->arr[n - a->count];
	}
}

void	push_back(t_record *r, t_stack *a, t_stack *b, int n)
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
			rotate_in_range(r, b, n, low, high);
			move_pa(r, a, b, n);
		}
		if (a->arr[n - a->count] > a->arr[n - a->count + 1])
			move_swap(r, a, n);
	}
	if (b->count > 0)
	{
		if (a->arr[n - a->count] > a->arr[n - a->count + 1])
			move_swap(r, a, n);
		move_pa(r, a, b, n);
	}
}

void	push_in_chunks(t_record *r, t_stacks *stacks)
{
	int	chunk_size = stacks->size / CHUNK_COUNT;
	if (chunk_size == 0)
		chunk_size = 1;
	int	chunk_count = stacks->size / chunk_size;
	int	num_pushed = 0;

	while (chunk_count > 0)
	{
		if (chunk_count == 1)
			chunk_size += stacks->size % chunk_size;
		int	i = chunk_size;
		while (stacks->a->count > 3 && i > 0)
		{
			int high = num_pushed + chunk_size - 1;
			if (chunk_count == 1)
				high -= 3;
			rotate_in_range(r, stacks->a, stacks->size, num_pushed, high);
			move_pb(r, stacks->a, stacks->b, stacks->size);
			if (stacks->b->arr[stacks->size - stacks->b->count] < (num_pushed + (chunk_size / 2)))
				move_rotate(r, stacks->b, stacks->size);
			i--;
		}
		num_pushed += chunk_size;
		chunk_count--;
	}
	if (!array_is_sorted(stacks->a->arr, stacks->size))
		sort_three(r, stacks->a, stacks->size);
	stack_print(stacks->a, stacks->b, stacks->size);
	push_back(r, stacks->a, stacks->b, stacks->size);
}

void	sort_stack(t_record *r, t_stacks *stacks)
{
	if (stacks->size == 2)
		move_swap(r, stacks->a, stacks->size);
	else if (stacks->size == 3)
		sort_three(r, stacks->a, stacks->size);
	else
		push_in_chunks(r, stacks);
	if (!r->str)
		return ;
	ft_putstr_fd(r->str, 1);
	free(r->str);
	if (stacks->size == stacks->a->count && array_is_sorted(stacks->a->arr, stacks->size))
		printf("sorted!\n");
	printf("move_count: %d\n", r->move_count);
}

int push_swap(int *a, int *b, int n)
{
	struct t_stacks stacks;
	struct t_stack	a_stack;
	struct t_stack	b_stack;
	struct t_record r;

	if (array_is_sorted(a, n))
		return (1);
	if (!record_init(&r))
		return (0);
	a_stack.arr = a;
	a_stack.count = n;
	a_stack.id = STACK_A;
	b_stack.arr = b;
	b_stack.count = 0;
	b_stack.id = STACK_B;
	stack_init(&stacks, &a_stack, &b_stack, n);
	array_normalize(a, n);
	sort_stack(&r, &stacks);
	return (1);
}

int	push_swap_init(int argc, char **argv, int **a, int **b)
{
	int	n;

	n = argc - 1;
	*a = array_alloc(n);
	*b = array_alloc(n);
	if (!*a || !*b)
	{
		free(*a);
		free(*b);
		return (0);
	}
	array_fill(*a, n, argv);
	return (1);
}

int main(int argc, char **argv)
{
	int	*a;
	int	*b;

	if (argc <= 1)
		return (0);
	if (!args_validate(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!push_swap_init(argc, argv, &a, &b))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	push_swap(a, b, argc - 1);
	free(a);
	free(b);
	return (0);
}
