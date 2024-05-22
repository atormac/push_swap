/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:36:58 by atorma            #+#    #+#             */
/*   Updated: 2024/05/22 21:39:13 by atorma           ###   ########.fr       */
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

int is_duplicate_str(char *s, int argc, char **argv)
{
	int	i;
	int	s_len;
	int	count;

	i = 1;
	s_len = ft_strlen(s);
	count = 0;
	while (i < argc)
	{
		if (ft_strncmp(s, argv[i], s_len) == 0)
			count++;
		if (count > 1)
			return (0);
		i++;
	}
	return (1);
}

int	args_validate(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_digit_str(argv[i]))
			return (0);
		if (!is_duplicate_str(argv[i], argc, argv))
			return (0);
		i++;
	}
	return (1);
}
