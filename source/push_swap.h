/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atorma <atorma@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:13:48 by atorma            #+#    #+#             */
/*   Updated: 2024/05/28 16:29:21 by atorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_WAP_H

int		args_validate(int argc, char **argv);
int		*array_alloc(int n);
void	array_fill(int *arr, int n, char **argv);
void	array_print(int *arr, int n);
void	array_stacks_print(int *a, int *b, int n);
int		array_is_sorted(int *arr, int n);

#endif
