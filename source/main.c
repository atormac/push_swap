/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:12:41 by atorma            #+#    #+#             */
/*   Updated: 2024/06/03 15:32:31 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_stack(t_stack *a, t_stack *b, int n)
{
	if (n == 2)
	{
		move_sa(a, n);
		stack_print(a, b, n);
	}
	else
	{
		int	num = 0;
		while (a->count > 0)
		{
			int a_top = n - a->count;
		//	int	b_top = n - b->count;
			int	current = a->arr[a_top];
			while (current != num)
			{
				move_rotate(a, n);
				stack_print(a, b, n);
				current = a->arr[n - a->count];
			}
			move_pb(a, b, n);
			num++;
			stack_print(a, b, n);
		}
		while (b->count > 0)
			move_pa(a, b, n);
	}
}

int push_swap(int *a, int *b, int n)
{
	struct t_stack	a_stack;
	struct t_stack	b_stack;

	if (array_is_sorted(a, n))
		return (1);
	a_stack.arr = a;
	a_stack.count = n;
	b_stack.arr = b;
	b_stack.count = 0;
	array_normalize(a, n);
	stack_print(&a_stack, &b_stack, n);
	printf("sorting...\n");
	sort_stack(&a_stack, &b_stack, n);
	printf("finished...\n");
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
