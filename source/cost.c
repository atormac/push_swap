#include "push_swap.h"

int	cost_top(t_stack *s, int n, int low, int high)
{
	int i;
	int	move_count;

	move_count = 0;
	i = n - s->count;
	while (i < s->count)
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
