/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:01:51 by atorma            #+#    #+#             */
/*   Updated: 2024/06/10 20:35:45 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stacks *stacks, t_stack *a, t_stack *b, int n)
{
	stacks->size = n;
	stacks->a = a;
	stacks->b = b;
}

/*void	stack_print(t_stack *a_stack, t_stack *b_stack, int n)
{
	int i;
	int	*a;
	int	*b;

	i = 0;
	a = a_stack->arr;
	b = b_stack->arr;
	ft_putstr_fd("--- stacks ---\n", 1);
	while (i < n)
	{
		ft_putstr_fd("a:\t", 1);
		ft_putnbr_fd(a[i], 1);
		ft_putstr_fd("\tb:\t", 1);
		ft_putnbr_fd(b[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}
*/
