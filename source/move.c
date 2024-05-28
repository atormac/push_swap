/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:27:16 by atorma            #+#    #+#             */
/*   Updated: 2024/05/28 17:34:43 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_sa(t_stack *a_stack)
{
	int	tmp;
	if (a_stack->count_element <= 1)
		return ;
	tmp = a_stack->arr[1];
	a_stack->arr[1] = a_stack->arr[0];
	a_stack->arr[0] = tmp;

}
