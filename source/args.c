/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:36:58 by atorma            #+#    #+#             */
/*   Updated: 2024/06/10 16:19:31 by atorma           ###   ########.fr       */
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

int	is_arg_valid(char *str, int *out_size)
{
	char	*token;

	if (*str == '\0' || str[ft_strlen(str) - 1] == ' ')
		return (0);
	token = ft_strtok_strict(str, " ");
	while (token != NULL)
	{
		if (*token == '\0')
			return (0);
		if (!is_digit_str(token))
			return (0);
		if (is_overflow(token))
			return (0);
		*out_size = *out_size + 1;
		token = ft_strtok_strict(NULL, " ");
	}
	return (1);
}

int	args_validate(int argc, char **argv, int *out_size)
{
	char	*str;
	int		i;

	i = 1;
	*out_size = 0;
	while (i < argc)
	{
		str = ft_strdup(argv[i]);
		if (!str)
			return (0);
		if (!is_arg_valid(str, out_size))
		{
			free(str);
			return (0);
		}
		free(str);
		i++;
	}
	return (1);
}
