/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:12:41 by atorma            #+#    #+#             */
/*   Updated: 2024/05/22 21:38:40 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc <= 1 || !args_validate(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	ft_putstr_fd("push_swap\n", 1);
	return (0);
}
