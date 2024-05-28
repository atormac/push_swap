/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:12:41 by atorma            #+#    #+#             */
/*   Updated: 2024/05/28 16:29:51 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push_swap(int *a, int *b)
{
	(void)a;
	(void)b;
	return (1);
}

int	push_swap_init(int argc, char **argv, int **a, int **b)
{
	*a = array_alloc(argc - 1);
	*b = array_alloc(argc - 1);
	if (!*a || !*b)
	{
		free(*a);
		free(*b);
		return (0);
	}
	array_fill(*a, argc - 1, argv);
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
	array_stacks_print(a, b, argc - 1);
	if (!array_is_sorted(a, argc - 1))
		push_swap(a, b);
	return (0);
}
