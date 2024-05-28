/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:27:16 by atorma            #+#    #+#             */
/*   Updated: 2024/05/28 17:39:56 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_sa(t_stack *stack)
{
	int	tmp;
	if (stack->count_element <= 1)
		return ;
	tmp = stack->arr[1];
	stack->arr[1] = stack->arr[0];
	stack->arr[0] = tmp;

}

void	move_sb(t_stack *stack)
{
	move_sa(stack);
}

void	move_ss(t_stack *a_stack, t_stack *b_stack)
{
	move_sa(a_stack);
	move_sb(b_stack);
}
