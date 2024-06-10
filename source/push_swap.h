/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:13:48 by atorma            #+#    #+#             */
/*   Updated: 2024/06/10 13:45:43 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_WAP_H

# define CHUNK_COUNT 5

enum
{
	STACK_A,
	STACK_B
};

typedef struct t_stack
{
	int		id;
	long	count;
	int		*arr;
}	t_stack;

typedef struct t_stacks
{
	long	size;
	t_stack *a;
	t_stack *b;
}	t_stacks;

typedef struct t_record
{
	int		move_count;
	char	*str;
	size_t	buffer_size;
	int		last_move;
}	t_record;

enum
{
	MV_EMPTY,
	MV_SA,
	MV_SB,
	MV_PA,
	MV_PB,
	MV_RA,
	MV_RRA,
	MV_RB,
	MV_RRB,
	MV_RR
};

int		has_duplicates(int *arr, int i);
int		args_validate(int argc, char **argv, int *out_size);
int		*array_alloc(int n);
int		array_fill(int *arr, int n, char **argv);
int		array_normalize(int *arr, int n);
int		array_is_sorted(int *arr, int n);
void	stack_init(t_stacks *stacks, t_stack *a, t_stack *b, int n);
int		cost_top(t_stack *s, int n, int low, int high);
int		cost_down(t_stack *s, int n, int low, int high);
int		cost_min(int *arr, int count);
int		cost_max(int *arr, int count);
void	move_swap(t_record *r, t_stack *a, int n);
void	move_push(t_record *r, t_stack *from, t_stack *to, int n);
void	move_sb(t_record *r, t_stack *b, int n);
void	move_rotate(t_record *r, t_stack *s, int n);
void	move_rev_rotate(t_record *r, t_stack *s, int n);
int		record_init(t_record *r);
int		record_move(t_record *r, int move);
void	chunk_rotate_top(t_record *r, t_stack *a, int n, int low, int high);
void	chunk_push_back(t_record *r, t_stack *a, t_stack *b, int n);
void	chunk_push(t_record *r, t_stacks *stacks, int chunk_count, int chunk_size);
void	sort_array(int *tab, int size);
void	sort_three(t_record *r, t_stack *s, int n);
void	sort_chunked(t_record *r, t_stacks *stacks);
void	sort_stack(t_record *r, t_stacks *stacks);

#endif
