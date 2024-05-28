#include "push_swap.h"

int *array_alloc(int argc, char **argv)
{
	int	*ret;
	int	i;
	int	n;

	i = 0;
	n = argc - 1;
	ret = malloc(sizeof(int) * n);
	if (!ret)
		return (NULL);
	while (i < n)
	{
		ret[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (ret);
}

void	array_print(int *arr, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putnbr_fd(arr[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
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
