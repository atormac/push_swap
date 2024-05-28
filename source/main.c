/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:12:41 by atorma            #+#    #+#             */
/*   Updated: 2024/05/28 15:40:07 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int	*arr;
	if (argc <= 1)
		return (0);
	if (!args_validate(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	arr = array_alloc(argc, argv);
	if (!arr)
		return (0);
	array_print(arr, argc - 1);
	if (array_is_sorted(arr, argc - 1))
		ft_putstr_fd("sorted!\n", 1);
	else
		ft_putstr_fd("not sorted!\n", 1);
	return (0);
}
