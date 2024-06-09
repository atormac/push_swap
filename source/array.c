#include "push_swap.h"

int *array_alloc(int n)
{
	int	*ret;

	ret = malloc(sizeof(int) * n);
	if (!ret)
		return (NULL);
	ft_memset(ret, -1, sizeof(int) * n);
	return (ret);
}

#include <string.h>
#include <stdio.h>

void	array_fill(int *arr, int n, char **argv)
{
	char	*token;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < n)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
		token = ft_strtok(argv[i], " ");
		while (token != NULL)
		{
			printf("token: %s\n", token);
			arr[j] = ft_atoi(token);
			j++;
			token = ft_strtok(NULL, " ");
		}
		i++;
	}
}

int	find_index(int *arr, int n, int value)
{
	int i = 0;
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
