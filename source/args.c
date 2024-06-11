/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:36:58 by atorma            #+#    #+#             */
/*   Updated: 2024/06/11 17:03:37 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	is_digit_str(char *s)
{
	if (*s == '-' && *(s + 1))
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	has_duplicates(int *arr, int i)
{
	int	val;

	val = arr[i];
	i--;
	while (i >= 0)
	{
		if (arr[i] == val)
			return (1);
		i--;
	}
	return (0);
}

int	is_overflow(char *s)
{
	int	num;

	if (ft_strlen(s) > 5)
	{
		num = ft_atoi(s);
		if (num == -1 || num == 0)
			return (1);
	}
	return (0);
}

int	is_arg_valid(char *str)
{
	if (*str == '\0')
		return (0);
	if (!is_digit_str(str))
		return (0);
	if (is_overflow(str))
		return (0);
	return (1);
}

int	args_validate(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!is_arg_valid(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
