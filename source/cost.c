#include "push_swap.h"

int	cost_top(t_stack *s, int n, int low, int high)
{
	int i;
	int	move_count;

	move_count = 0;
	i = n - s->count;
	while (i < n)
	{
		if (s->arr[i] >= low && s->arr[i] <= high)
			break;
		i++;
		move_count++;
	}
	return (move_count);
}

int	cost_down(t_stack *s, int n, int low, int high)
{
	int i;
	int	move_count;

	move_count = 1;
	i = n - 1;
	while (i >= s->count)
	{
		if (s->arr[i] >= low && s->arr[i] <= high)
			break;
		i--;
		move_count++;
	}
	return (move_count);
}

int	cost_min(int *arr, int count)
{
	int i = 0;
	int	min;
	int	min_index;

	min = arr[0];
	min_index = 0;
	while (i < count)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	cost_max(int *arr, int count)
{
	int i = 0;
	int	max;
	int	max_index;

	max = arr[0];
	max_index = 0;
	while (i < count)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}
