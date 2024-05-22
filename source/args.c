/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:36:58 by atorma            #+#    #+#             */
/*   Updated: 2024/05/22 21:59:29 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int is_digit_str(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int is_duplicate_str(char *s, int i, char **argv)
{
	int	s_len;

	s_len = ft_strlen(s);
	while (i >= 1)
	{
		if (ft_strncmp(s, argv[i], s_len) == 0)
			return (0);
		i--;
	}
	return (1);
}
#include <stdio.h>
int	args_validate(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_digit_str(argv[i]))
			return (0);
		if (!is_duplicate_str(argv[i], i - 1, argv))
			return (0);
		i++;
	}
	return (1);
}
