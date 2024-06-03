/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:12:41 by atorma            #+#    #+#             */
/*   Updated: 2024/06/03 19:40:06 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	get_distance_top(int *arr, int n, int val)
{
	int i = 0;

	while (i < n)
	{
		if (arr[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

void	sort_insertion_sort(t_record *r, t_stack *a, t_stack *b, int n)
{
	int	num = 0;
	int	rotate;

	while (a->count > 1)
	{
		rotate = 1;
		int a_top = n - a->count;
		int	current = a->arr[a_top];
		int	dist = get_distance_top(a->arr + a_top, a->count, num);
		if (dist > a->count / 2)
			rotate = 0;
		while (current != num)
		{
			if (rotate)
				move_rotate(r, a, n);
			else
				move_rev_rotate(r, a, n);
			current = a->arr[n - a->count];
		}
		move_pb(r, a, b, n);
		num++;
	}
	while (b->count > 0)
		move_pa(r, a, b, n);
}

void	sort_small(t_record *r, t_stack *a, t_stack *b, int n)
{
	if (n == 2)
		move_sa(a, n);
	(void)b;
	(void)r;
}

void	sort_stack(t_record *r, t_stack *a, t_stack *b, int n)
{
	if (n == 2)
		sort_small(r, a, b, n);
	else
		sort_insertion_sort(r, a, b, n);
	printf("move_count: %d\n", r->move_count);
	ft_putstr_fd(r->str, 1);
	free(r->str);
}

int push_swap(int *a, int *b, int n)
{
	struct t_stack	a_stack;
	struct t_stack	b_stack;
	struct t_record r;

	if (array_is_sorted(a, n))
		return (1);
	a_stack.arr = a;
	a_stack.count = n;
	b_stack.arr = b;
	b_stack.count = 0;
	r.move_count = 0;
	r.str = NULL;
	array_normalize(a, n);
	stack_print(&a_stack, &b_stack, n);
	sort_stack(&r, &a_stack, &b_stack, n);
	printf("\nfinished...\n");
	stack_print(&a_stack, &b_stack, n);
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
