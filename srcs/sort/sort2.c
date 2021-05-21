/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:24:01 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/20 23:31:19 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operation.h"
#include "libft.h"

#include "test.h"
#include <stdio.h>

int		init_sort(t_stack *stack, int *pivot, int *operation)
{
	int		i;

	(void)pivot;
	(void)stack;
//	get_pivot(stack, &pivot[0], 1);
//	get_pivot(stack, &pivot[1], 2);
	i = 0;
	while (i < 4)
	{
		operation[i] = 0;
		i++;
	}
	return (0);
}

int		b_to_a(t_pair *pair, int time)
{
	int		pivot[2];
	int		operation[4];
	int		i;

	if (time <= 1)
	{
		push_a(pair);
		return (1);
	}
	if (is_sorted(&pair->b, 'b'))
		while (pair->b.size)
			push_a(pair);
	if (pair->b.size <= 3)
	{
		sort_2_nodes(&pair->b, 'b');
		if (pair->b.size == 3)
			sort_3_nodes(&pair->b, 'b');
		while (pair->b.size)
			push_a(pair);
		return (1);
	}
	init_sort(&pair->b, pivot, operation);
	get_pivot(&pair->b, &pivot[0], 2);
	printf("b) pivot[0], pivot[1]: %d, %d\n", pivot[0], pivot[1]);
//	if (time == 2)
//		if (pair->b.head->value < pair->b.head->next->value)
//			swap(&pair->b, 'b');
	while (time--)
	{
		if (pair->b.head->value < pivot[0])
		{
			rotate(&pair->b, 'b');
			operation[RB]++;
		}
		else
		{
			push_a(pair);
			operation[PA]++;
		}
		test_stack(pair);
	}
	i = 0;
	while (i++ < operation[RB])
		rev_rotate(&pair->b, 'b');
	a_to_b(pair, operation[PA]);
	b_to_a(pair, operation[RB]);
	return (1);
}

int		a_to_b(t_pair *pair, int time)
{
	int		pivot[2];
	int		operation[4];
	int		i;
	int		rev;

	if (time <= 1)
		return (1);
	if (is_sorted(&pair->a, 'a'))
		return (1);
	if (pair->a.size <= 3)
	{
		sort_2_nodes(&pair->a, 'a');
		if (pair->a.size == 3)
			sort_3_nodes(&pair->a, 'a');
		return (1);
	}
	init_sort(&pair->a, pivot, operation);
	get_pivot(&pair->a, &pivot[0], 1);
	printf("pivot[0], pivot[1]: %d, %d\n", pivot[0], pivot[1]);
	get_direction(&pair->a, pivot[1], &rev, 'a');
	while (time--)
	{
		if (pair->a.head->value > pivot[0])
		{
			rotate(&pair->a, 'a');
			operation[RA]++;
		}
		else
		{
			push_b(pair);
			operation[PB]++;
		}
		test_stack(pair);
	}
	i = 0;
	while (i++ < operation[RA])
		rev_rotate(&pair->a, 'a');
	if (is_sorted(&pair->a, 'a'))
		return (1);
	a_to_b(pair, operation[RA]);
//	b_to_a(pair, operation[PB]);
	return (1);
}
