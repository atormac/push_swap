/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:36:58 by atorma            #+#    #+#             */
/*   Updated: 2024/06/03 21:00:55 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int is_digit_str(char *s)
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

int is_duplicate_str(char *s, int i, char **argv)
{
	int	s_len;
	int	arg_len;

	while (i >= 1)
	{
		s_len = ft_strlen(s);
		arg_len = ft_strlen(argv[i]);
		if (arg_len > s_len)
			s_len = arg_len;
		if (ft_strncmp(s, argv[i], s_len) == 0)
			return (0);
		i--;
	}
	return (1);
}

int is_overflow(char *s)
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

int	is_token_valid(char *token)
{
	if (*token == '\0')
		return (0);
	if (!is_digit_str(token))
		return (0);
	if (is_overflow(token))
		return (0);
	return (1);
}

int	args_validate(int argc, char **argv, int *out_size)
{
	char	*str;
	char	*token;
	int	i;

	i = 1;
	*out_size = 0;
	while (i < argc)
	{
		str = ft_strdup(argv[i]);
		if (!str)
			return (0);
		token = ft_strtok_strict(str, " ");
		while (token != NULL)
		{
			if (!is_token_valid(token))
			{
				free(str);
				return (0);
			}
			*out_size = *out_size + 1;
			token = ft_strtok_strict(NULL, " ");
		}
		free(str);
		i++;
	}
	return (1);
}
