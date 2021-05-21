/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:31:31 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/22 05:08:09 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operation.h"

void	init_sort(t_stack *stack, int *pivot, int time, t_operation *op)
{
	op->ra = 0;
	op->rb = 0;
	op->pa = 0;
	op->pb = 0;
	get_pivot(stack, &pivot[0], time, 1);
	get_pivot(stack, &pivot[1], time, 2);
}

int		presort_before_sort(t_pair *pair, int time, int t)
{
	int		dump;

	if (time > 3)
		return (0);
	sort_few_nodes(pair, time, t);
	if (t == 'b')
		if (time == 1)
			pa(pair, &dump, 1);
	return (1);
}

void	resort_after_sort(t_pair *pair, t_operation *op)
{
	int		i;

	i = op->rb;
	if (op->ra < op->rb)
		i = op->ra;
	while (i--)
		rrr(pair, 1);
	i = op->rb - op->ra;
	if (i < 0)
		while (i++)
			rra(&pair->a, 1);
	else
		while (i--)
			rrb(&pair->b, 1);
}

void	b_to_a(t_pair *pair, int time)
{
	t_operation	op;
	int			pivot[2];

	if (is_sorted(&pair->b, 'b', time))
	{
		while (time--)
			pa(pair, &op.pa, 1);
		return ;
	}
	if (presort_before_sort(pair, time, 'b'))
		return ;
	if (sort_few_times(pair, time, 'b'))
		return ;
	init_sort(&pair->b, pivot, time, &op);
	while (time--)
		if (pair->b.head->value < pivot[0])
			rb(&pair->b, &op.rb, 1);
		else
		{
			pa(pair, &op.pa, 1);
			if (pair->a.head->value < pivot[1])
				ra(&pair->a, &op.ra, 1);
		}
	a_to_b(pair, op.pa - op.ra);
	resort_after_sort(pair, &op);
	a_to_b(pair, op.ra);
	b_to_a(pair, op.rb);
}

void	a_to_b(t_pair *pair, int time)
{
	t_operation	op;
	int			pivot[2];

	if (is_sorted(&pair->a, 'a', time))
		return ;
	if (presort_before_sort(pair, time, 'a'))
		return ;
	if (sort_few_times(pair, time, 'a'))
		return ;
	init_sort(&pair->a, pivot, time, &op);
	while (time--)
	{
		if (pair->a.head->value > pivot[1])
			ra(&pair->a, &op.ra, 1);
		else
		{
			pb(pair, &op.pb, 1);
			if (pair->b.head->value > pivot[0])
				rb(&pair->b, &op.rb, 1);
		}
	}
	resort_after_sort(pair, &op);
	a_to_b(pair, op.ra);
	b_to_a(pair, op.rb);
	b_to_a(pair, op.pb - op.rb);
}
