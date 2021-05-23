/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_23_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 15:53:01 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/23 16:39:25 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operation.h"

void	sort_2_nodes(t_stack *stack, int type)
{
	t_node	*node;
	int		dump;

	node = stack->head;
	if (type == 'a')
	{
		if (node->value > node->next->value)
			sa(stack, &dump, 1);
	}
	else
		if (node->value < node->next->value)
			sb(stack, &dump, 1);
}

void	sort_3_nodes_b(t_pair *pair)
{
	int		min;
	int		max;
	int		dump;
	t_node	*node;

	min = get_min(pair->b.head, pair->b.size);
	max = get_max(pair->b.head, pair->b.size);
	node = pair->b.head;
	while (!is_sorted(&pair->b, 'b', pair->b.size))
	{
		if ((node->value == max && node->next->value == min) ||
			(node->next->value == max && node->next->next->value == min) ||
			(node->value == min && node->next->next->value == max))
			sb(&pair->b, &dump, 1);
		else if (node->value == min && node->next->value == max)
			rb(&pair->b, &dump, 1);
		else if (node->next->value == min && node->next->next->value == max)
			rrb(&pair->b, 1);
	}
}

void	sort_3_nodes_a(t_pair *pair)
{
	int		min;
	int		max;
	int		dump;
	t_node	*node;

	min = get_min(pair->a.head, pair->a.size);
	max = get_max(pair->a.head, pair->a.size);
	node = pair->a.head;
	while (!is_sorted(&pair->a, 'a', pair->a.size))
	{
		if ((node->value == min && node->next->value == max) ||
			(node->next->value == min && node->next->next->value == max) ||
			(node->value == max && node->next->next->value == min))
			sa(&pair->a, &dump, 1);
		if (node->value == max && node->next->value == min)
			ra(&pair->a, &dump, 1);
		if (node->next->value == max && node->next->next->value == min)
			rra(&pair->a, 1);
	}
}

int		sort_23_nodes(t_pair *pair, t_stack *stack, int type)
{
	int		dump;

	if (stack->size != 2 && stack->size != 3)
		return (0);
	if (stack->size == 2)
	{
		sort_2_nodes(stack, type);
		if (type == 'b')
			while (pair->b.size)
				pa(pair, &dump, 1);
	}
	else
		if (type == 'a')
			sort_3_nodes_a(pair);
		else
		{
			sort_3_nodes_b(pair);
			while (pair->b.size)
				pa(pair, &dump, 1);
		}
	return (1);
}
