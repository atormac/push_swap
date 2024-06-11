/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:41:37 by atorma            #+#    #+#             */
/*   Updated: 2024/06/10 21:30:07 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_get(char *str, int move)
{
	char	*mv;

	if (move == MV_SA)
		mv = "sa";
	if (move == MV_SB)
		mv = "sb";
	if (move == MV_PA)
		mv = "pa";
	if (move == MV_PB)
		mv = "pb";
	if (move == MV_RA)
		mv = "ra";
	if (move == MV_RRA)
		mv = "rra";
	if (move == MV_RB)
		mv = "rb";
	if (move == MV_RRB)
		mv = "rrb";
	if (move == MV_RR)
		mv = "rr";
	ft_strlcpy(str, mv, ft_strlen(mv) + 1);
}

static void	move_write(t_record *r, char	*mv)
{
	ft_strlcat(r->str, mv, r->buffer_size);
	ft_strlcat(r->str, "\n", r->buffer_size);
}

int	record_init(t_record *r)
{
	r->buffer_size = 0;
	r->move_count = 0;
	r->last_move = MV_EMPTY;
	r->str = ft_calloc(1, 2048);
	if (r->str == NULL)
		return (0);
	r->buffer_size = 2048;
	return (1);
}

int	record_append_str(t_record *r, int move)
{
	char	mv[16];

	move_get(mv, move);
	if (r->last_move == MV_RB)
	{
		if (move == MV_RA)
		{
			move_get(mv, MV_RR);
			move_write(r, mv);
			r->last_move = MV_RR;
			return (1);
		}
		move_get(mv, r->last_move);
		move_write(r, mv);
		move_get(mv, move);
	}
	if (move != MV_RB)
		move_write(r, mv);
	r->last_move = move;
	return (1);
}

int	record_move(t_record *r, int move)
{
	char	*new;

	if (r->str == NULL)
		return (0);
	if (r->buffer_size - ft_strlen(r->str) < 32)
	{
		new = ft_calloc(1, r->buffer_size + 1024);
		if (!new)
		{
			free(r->str);
			r->str = NULL;
			return (0);
		}
		ft_memcpy(new, r->str, r->buffer_size);
		free(r->str);
		r->str = new;
		r->buffer_size += 1024;
	}
	record_append_str(r, move);
	r->move_count++;
	return (1);
}
