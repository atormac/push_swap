/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:13:47 by atorma            #+#    #+#             */
/*   Updated: 2024/06/11 16:35:45 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*array_alloc(int n)
{
	int	*ret;

	ret = malloc(sizeof(int) * n);
	if (!ret)
		return (NULL);
	ft_memset(ret, -1, sizeof(int) * n);
	return (ret);
}

int	array_fill(int *arr, int n, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < n)
	{
		arr[j] = ft_atoi(argv[i]);
		if (has_duplicates(arr, j))
			return (0);
		j++;
		i++;
	}
	return (1);
}

int	find_index(int *arr, int n, int value)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	array_normalize(int *arr, int n)
{
	int	*tab;
	int	i;

	tab = array_alloc(n);
	if (!tab)
		return (0);
	ft_memcpy(tab, arr, n * sizeof(int));
	sort_array(tab, n);
	i = 0;
	while (i < n)
	{
		arr[i] = find_index(tab, n, arr[i]);
		i++;
	}
	free(tab);
	return (1);
}

int	array_is_sorted(int *arr, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		if (arr[i] < arr[i - 1])
			return (0);
		i++;
	}
	return (1);
}
