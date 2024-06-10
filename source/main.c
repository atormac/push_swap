/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:12:41 by atorma            #+#    #+#             */
/*   Updated: 2024/06/10 13:00:09 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error()
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int	push_swap_init(int argc, char **argv, int size, int **a, int **b)
{
	int	n;

	n = size - 1;
	*a = array_alloc(n + 1);
	*b = array_alloc(n + 1);
	if (!*a || !*b || !array_fill(*a, argc, argv))
	{
		free(*a);
		free(*b);
		return (0);
	}
	return (1);
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
		return (error());
	if (!array_normalize(a, n))
		return (error());
	a_stack.arr = a;
	a_stack.count = n;
	a_stack.id = STACK_A;
	b_stack.arr = b;
	b_stack.count = 0;
	b_stack.id = STACK_B;
	stack_init(&stacks, &a_stack, &b_stack, n);
	sort_stack(&r, &stacks);
	return (1);
}

int main(int argc, char **argv)
{
	int	size;
	int	*a;
	int	*b;

	if (argc <= 1)
		return (0);
	if (!args_validate(argc, argv, &size))
		return error();
	if (!push_swap_init(argc, argv, size, &a, &b))
		return error();
	push_swap(a, b, size);
	free(a);
	free(b);
	return (0);
}
