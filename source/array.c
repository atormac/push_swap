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

void	array_fill(int *arr, int n, char **argv)
{
	int	i;

	i = 0;
	while (i < n)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

void	ft_sort_arr(int *tab, int size)
{
	int		tmp;
	int		x;
	int		i;

	i = 0;
	while (i < size)
	{
		x = i + 1;
		while (x < size)
		{
			if (tab[i] > tab[x])
			{
				tmp = tab[i];
				tab[i] = tab[x];
				tab[x] = tmp;
			}
			x++;
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

void	array_normalize(int *arr, int n)
{
	int	*tab;
	int	i;

	tab = array_alloc(n);
	if (!tab)
		return ;
	ft_memcpy(tab, arr, n * sizeof(int));
	ft_sort_arr(tab, n);
	i = 0;
	while (i < n)
	{
		arr[i] = find_index(tab, n, arr[i]);
		i++;
	}
	free(tab);
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
