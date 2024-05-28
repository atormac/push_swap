/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:27:16 by atorma            #+#    #+#             */
/*   Updated: 2024/05/28 18:11:22 by atorma           ###   ########.fr       */
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

void	move_pa(t_stack *a_stack, t_stack *b_stack)
{
	if (b_stack->count_element == 0)
		return ;
	a_stack->arr[0] = a_stack->arr[0];
}

void	move_pb(t_stack *a_stack, t_stack *b_stack)
{
	if (a_stack->count_element == 0)
		return ;
	b_stack->arr[0] = a_stack->arr[0];
	b_stack->count_element++;
}
