/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:13:48 by atorma            #+#    #+#             */
/*   Updated: 2024/05/28 17:40:06 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_WAP_H

typedef struct t_stack
{
	long count_element;
	int *arr;
}	t_stack;

int		args_validate(int argc, char **argv);
int		*array_alloc(int n);
void	array_fill(int *arr, int n, char **argv);
void	array_print(int *arr, int n);
int		array_is_sorted(int *arr, int n);
void	stack_print(t_stack *a_stack, t_stack *b_stack, int n);
void	move_sa(t_stack *a_stack);
void	move_sb(t_stack *stack);
void	move_ss(t_stack *a_stack, t_stack *b_stack);

#endif
