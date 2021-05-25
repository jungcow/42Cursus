/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few_times.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 02:01:50 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/25 18:02:11 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operation.h"

void	init_operation(t_operation *op)
{
	op->ra = 0;
	op->rb = 0;
	op->pa = 0;
	op->pb = 0;
}

int		pre_sort_few(t_pair *pair, t_operation *op, int time)
{
	if (time < 2)
	{
		pa(pair, &op->pa, 1);
		return (1);
	}
	if (is_sorted(&pair->b, 'b', time))
	{
		while (time--)
			pa(pair, &op->pa, 1);
		return (1);
	}
	return (0);
}

void	sort_few_times_b(t_pair *pair, int time)
{
	int			pivot;
	int			i;
	t_operation	op;

	if (pre_sort_few(pair, &op, time))
		return ;
	if (sort_23_nodes(pair, &pair->b, 'b') || sort_23_times(pair, time, 'b', 0))
		return ;
	get_pivot(&pair->b, &pivot, time, 1.0);
	init_operation(&op);
	while (time--)
	{
		if (pair->a.head->value >= pivot)
			pa(pair, &op.pa, 1);
		else
			rb(&pair->b, &op.rb, 1);
	}
	i = 0;
	while (i++ < op.rb && pair->b.size > 3)
		rrb(&pair->b, 1);
	sort_few_times_a(pair, op.pa);
	sort_few_times_b(pair, op.rb);
}

void	sort_few_times_a(t_pair *pair, int time)
{
	int			pivot;
	int			i;
	t_operation	op;

	if (time < 2)
		return ;
	if (is_sorted(&pair->a, 'a', time))
		return ;
	if (sort_23_nodes(pair, &pair->a, 'a') || sort_23_times(pair, time, 'a', 0))
		return ;
	init_operation(&op);
	get_pivot(&pair->a, &pivot, time, 1.0);
	while (time--)
	{
		if (pair->a.head->value > pivot)
			ra(&pair->a, &op.ra, 1);
		else
			pb(pair, &op.pb, 1);
	}
	i = 0;
	while (i++ < op.ra && pair->a.size > 3)
		rra(&pair->a, 1);
	sort_few_times_a(pair, op.ra);
	sort_few_times_b(pair, op.pb);
}

int		sort_few_times(t_pair *pair, int time, int type)
{
	t_stack	*stack;

	stack = &pair->a;
	if (type == 'b')
		stack = &pair->b;
	if (stack->size > 5)
		return (0);
	if (type == 'a')
		sort_few_times_a(pair, time);
	else if (type == 'b')
		sort_few_times_b(pair, time);
	return (1);
}
