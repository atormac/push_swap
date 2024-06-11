/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:01:51 by atorma            #+#    #+#             */
/*   Updated: 2024/06/11 17:06:42 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stacks *stacks, t_stack *a, t_stack *b, int n)
{
	stacks->size = n;
	stacks->a = a;
	stacks->b = b;
}
