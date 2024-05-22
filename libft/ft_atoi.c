/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:34:18 by atorma            #+#    #+#             */
/*   Updated: 2024/05/22 22:26:03 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	if (c == '\t' || c == ' ' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			res;
	const char	*s;
	int			overflow;

	res = 0;
	s = str;
	while (is_whitespace(*s))
		s++;
	str = s;
	if (*s == '-' || *s == '+')
		s++;
	while (*s && *s >= '0' && *s <= '9')
	{
		overflow = res;
		res = res * 10 + (*s - '0');
		if (overflow > res)
		{
			if (*str == '-')
				return (0);
			return (-1);
		}
		s++;
	}
	if (res != 0 && *str == '-')
		res *= -1;
	return (res);
}
