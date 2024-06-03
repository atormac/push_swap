/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:41:37 by atorma            #+#    #+#             */
/*   Updated: 2024/06/03 21:10:20 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	record_append_str(char *str, int move)
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
	ft_strlcat(str, mv, 2048);
	ft_strlcat(str, "\n", 2048);
	return (1);
}

int	record_move(t_record *r, int move)
{
	if (r->str == NULL)
	{
		r->str = ft_calloc(1, 2048);
		if (r->str == NULL)
			return (-1);
	}
	record_append_str(r->str, move);
	r->move_count++;
	return (1);
}
