/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:13:48 by atorma            #+#    #+#             */
/*   Updated: 2024/06/03 19:00:18 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_WAP_H

typedef struct t_stack
{
	long count;
	int *arr;
}	t_stack;

typedef struct t_stacks
{
	long	n;
	t_stack *a;
	t_stack *b;
}	t_stacks;

typedef struct t_record
{
	int		move_count;
	char	*str;
}	t_record;

enum
{
	MV_SA,
	MV_SB,
	MV_SS,
	MV_PA,
	MV_PB,
	MV_RA,
	MV_RRA,
	MV_RB,
	MV_RRB
};

int		args_validate(int argc, char **argv);
int		*array_alloc(int n);
void	array_fill(int *arr, int n, char **argv);
void	array_normalize(int *arr, int n);
void	array_print(int *arr, int n);
int		array_is_sorted(int *arr, int n);
void	stack_print(t_stack *a_stack, t_stack *b_stack, int n);
void	move_sa(t_stack *a, int n);
void	move_sb(t_stack *b, int n);
void	move_ss(t_stack *a, t_stack *b, int n);
void	move_pa(t_record *r, t_stack *a, t_stack *b, int n);
void	move_pb(t_record *r, t_stack *a, t_stack *b, int n);
void	move_rotate(t_record *r, t_stack *s, int n);
void	move_rev_rotate(t_record *r, t_stack *s, int n);
int		record_move(t_record *r, int move);

#endif
