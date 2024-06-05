/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:12:41 by atorma            #+#    #+#             */
/*   Updated: 2024/06/05 23:22:09 by atorma           ###   ########.fr       */
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

	while (a->count > 0)
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

int	get_mvcount_top(t_stack *s, int n, int low, int high)
{
	int i;
	int	move_count;

	move_count = 0;
	i = n - s->count;
	while (i < s->count)
	{
		if (s->arr[i] >= low && s->arr[i] <= high)
			break;
		i++;
		move_count++;
	}
	return (move_count);
}

int	get_mvcount_bottom(t_stack *s, int n, int low, int high)
{
	int i;
	int	move_count;

	move_count = 1;
	i = n - 1;
	while (i >= s->count)
	{
		if (s->arr[i] >= low && s->arr[i] <= high)
			break;
		i--;
		move_count++;
	}
	return (move_count);
}

#define CHUNK_COUNT 5

void	push_cheapest(t_record *r, t_stack *a, t_stack *b, int n, int low, int high)
{
	int	mv_count_top;
	int	mv_count_bottom;

	mv_count_top = get_mvcount_top(a, n, low, high);
	mv_count_bottom = get_mvcount_bottom(a, n, low, high);
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
	move_pb(r, a, b, n);
}

void	push_back(t_record *r, t_stack *a, t_stack *b, int n)
{

}

void	push_in_chunks(t_record *r, t_stack *a, t_stack *b, int n)
{
	int	chunk_size = n / CHUNK_COUNT;
	int	chunk_count = n / chunk_size;
	int	num_pushed = 0;

	chunk_size += n % chunk_size;
	stack_print(a, b, n);
	while (chunk_count > 0)
	{
		int	i = chunk_size;
		while (i > 0)
		{
			int high = num_pushed + chunk_size - 1;
			push_cheapest(r, a, b, n, num_pushed, high);
			if (b->arr[n - b->count] < (num_pushed + (chunk_size / 2)))
			{
				printf("rotating: %d, median: %d\n", b->arr[n - b->count], (num_pushed + (chunk_size / 2)));
				move_rotate(r, b, n);
			}
			i--;
		}
		num_pushed += chunk_size;
		chunk_size = n / CHUNK_COUNT;
		chunk_count--;
	}
	stack_print(a, b, n);
	printf("move_count: %d, num_pushed %d\n", r->move_count, num_pushed);
	while (b->count > 0)
	{
		num_pushed--;
		/*int	second = num_pushed - 2;
		if (second < 0)
			second = num_pushed;
		if (num_pushed == 0)
			break;
			*/
		push_cheapest(r, b, a, n, num_pushed, num_pushed);
	}
	stack_print(a, b, n);
}

void	sort_stack(t_record *r, t_stack *a, t_stack *b, int n)
{
	if (n == 2)
		move_sa(r, a, n);
	else if (n == 3)
		sort_three(r, a, n);
	else
	{
		/*
		stack_print(a, b, n);
		sort_turkish(r, a, b, n);
		printf("\n");
		stack_print(a, b, n);
		*/
		push_in_chunks(r, a, b, n);
		//sort_insertion_sort(r, a, b, n);
	}
	if (!r->str)
		return ;
	//ft_putstr_fd(r->str, 1);
	free(r->str);
	printf("move_count: %d\n", r->move_count);
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
	//stack_print(&a_stack, &b_stack, n);
	sort_stack(&r, &a_stack, &b_stack, n);
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
