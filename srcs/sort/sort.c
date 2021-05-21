/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:31:31 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/21 04:09:32 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operation.h"

#include "test.h"
#include <stdio.h>
void	init_sort(t_stack *stack, int *pivot, int time, t_operation *op)
{
	op->ra = 0;
	op->rb = 0;
	op->pa = 0;
	op->pb = 0;
	get_pivot(stack, &pivot[0], time, 1);
	get_pivot(stack, &pivot[1], time, 2);
}

void	b_to_a(t_pair *pair, int time)
{
	t_operation	op;
	int			pivot[2];
	int			i;

//	printf("b: time: %d\n", time);
	if (pair->b.size <= 3)
	{
		sort_2_nodes(&pair->b, 'b');
		sort_3_nodes(&pair->b, 'b');
		while (pair->b.size)
			pa(pair, &op.pa);
		return ;
	}
	if (time < 3)
	{
		if (pair->b.head->value < pair->b.head->next->value)
			sb(&pair->b, &i);
		while (time--)
			pa(pair, &i);
		return ;
	}

	init_sort(&pair->b, pivot, time, &op);
//	printf("b) pivot1: %d, pivot2: %d\n", pivot[0], pivot[1]);
	i = time;
	while (i--)
	{
		if (pair->b.head->value < pivot[0])
			rb(&pair->b, &op.rb);
		else
		{
			pa(pair, &op.pa);
			if (pair->a.head->value < pivot[1])
				ra(&pair->a, &op.ra);
		}
	//	test_stack(pair);
	}
//	printf("ra: %d, rb: %d, pa: %d\n", op.ra, op.rb, op.pa);
	a_to_b(pair, op.pa - op.ra);
	i = op.rb;
	if (op.ra < op.rb)
		i = op.ra;
//	printf("i: %d\n", i);
	while (i--)
		rrr(pair);
	i = op.rb - op.ra;
	if (i < 0)
		while (i++)
			rra(&pair->a);
	else
		while (i--)
			rrb(&pair->b);
//	test_stack(pair);
	a_to_b(pair, op.ra);
	b_to_a(pair, op.rb);
}

void	a_to_b(t_pair *pair, int time)
{
	t_operation	op;
	int			pivot[2];
	int			i;

//	printf("a: time: %d\n", time);
	if (pair->a.size <= 3)
	{
		sort_2_nodes(&pair->a, 'a');
		sort_3_nodes(&pair->a, 'a');
		return ;
	}
	if (time < 3)
	{
		if (pair->a.head->value > pair->a.head->next->value)
			sa(&pair->a, &i);
	//	printf("time: %d\n", time);
	//	while (time--)
	//		pb(pair, &i);
		return ;
	}

	init_sort(&pair->a, pivot, time, &op);
//	printf("a) pivot1: %d, pivot2: %d\n", pivot[0], pivot[1]);
	i = time;
	while (i--)
	{
		if (pair->a.head->value >= pivot[1])
			ra(&pair->a, &op.ra);
		else
		{
			pb(pair, &op.pb);
			if (pair->b.head->value >= pivot[0])
				rb(&pair->b, &op.rb);
		}
	//	test_stack(pair);
	}
//	printf("ra: %d, rb: %d, pb: %d\n", op.ra, op.rb, op.pb);
	i = op.rb;
	if (op.ra < op.rb)
		i = op.ra;
//	printf("i: %d\n", i);
	while (i--)
		rrr(pair);
	i = op.rb - op.ra;
	if (i < 0)
		while (i++)
			rra(&pair->a);
	else
		while (i--)
			rrb(&pair->b);
//	test_stack(pair);
	a_to_b(pair, op.ra);
	b_to_a(pair, op.rb);
	b_to_a(pair, op.pb - op.rb);
}
