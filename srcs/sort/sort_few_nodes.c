/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few_nodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:51:58 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/22 05:07:37 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operation.h"

int		is_sorted(t_stack *stack, int type, int time)
{
	t_node	*node;
	int		num;

	node = stack->head;
	if (node)
		num = node->value;
	while (node && time--)
	{
		if (type == 'a' && node->value < num)
			return (0);
		else if (type == 'b' && node->value > num)
			return (0);
		else
			num = node->value;
		node = node->next;
	}
	return (1);
}

void	sort_2_nodes(t_pair *pair, t_stack *stack, int time, int type)
{
	int		min;
	int		max;
	int		dump;

	min = get_min(stack->head, time);
	max = get_max(stack->head, time);
	if (type == 'a')
	{
		if (stack->head->value == max && stack->head->next->value == min)
			sa(stack, &dump, 1);
		return ;
	}
	if (type == 'b')
		if (stack->head->value == min && stack->head->next->value == max)
			sb(stack, &dump, 1);
	while (time--)
		pa(pair, &dump, 1);
}

void	sort_3_nodes_a(t_pair *pair, int time, int min, int max)
{
	t_node	*node;
	int		dump;

	time = 0;
	node = pair->a.head;
//	while (!is_sorted(&pair->a, 'a', time))
		if (node->value == max ||
			(node->next->value == min && node->next->next->value == max))
		{
			sa(&pair->a, &dump, 1);
		}
		if (node->next->value == max && node->next->next->value == min)
		{
			pb(pair, &dump, 1);
			sa(&pair->a, &dump, 1);
			ra(&pair->a, &dump, 1);
			pa(pair, &dump, 1);
			rra(&pair->a, 1);
		}
		if (node->value == min && node->next->value == max)
		{
			pb(pair, &dump, 1);
			sa(&pair->a, &dump, 1);
			pa(pair, &dump, 1);
		}
}

void	sort_3_nodes_b(t_pair *pair, int time, int min, int max)
{
	t_node	*node;
	int		dump;

	time = 0;
	node = pair->b.head;
		if (node->value == min ||
			(node->next->value == max && node->next->next->value == min))
		{
			sb(&pair->b, &dump, 1);
		}
		if (node->next->value == min && node->next->next->value == max)
		{
			pa(pair, &dump, 1);
			sb(&pair->b, &dump, 1);
			rb(&pair->b, &dump, 1);
			pb(pair, &dump, 1);
			rrb(&pair->b, 1);
		}
		if (node->value == max && node->next->value == min)
		{
			pa(pair, &dump, 1);
			sb(&pair->b, &dump, 1);
			pb(pair, &dump, 1);
		}
}

int		sort_few_nodes(t_pair *pair, int time, int type)
{
	t_stack	*stack;
	int		min;
	int		max;
	int		dump;

	stack = &pair->b;
	if (type == 'a')
		stack = &pair->a;
	min = get_min(stack->head, time);
	max = get_max(stack->head, time);
	if (time != 2 && time != 3)
		return (0);
	if (time == 2)
		sort_2_nodes(pair, stack, time, type);
	if (time == 3)
	{
		if (type == 'a')
		{
			sort_3_nodes_a(pair, time, min, max);
		}
		else if (type == 'b')
		{
			sort_3_nodes_b(pair, time, min, max);
			while (time--)
				pa(pair, &dump, 1);
		}
	}
	return (1);
}
