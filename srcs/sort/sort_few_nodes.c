/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few_nodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:51:58 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/21 03:16:38 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operation.h"

int		is_sorted(t_stack *stack, int type)
{
	t_node	*node;
	int		num;

	node = stack->head;
	if (node)
		num = node->value;
	while (node)
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

void	sort_2_nodes(t_stack *stack, int type)
{
	int		max;
	int		min;
	int		dump;
	t_node	*node;

	if (stack->size != 2)
		return ;
	node = stack->head;
	min = get_min(node);
	max = get_max(node);
	if (type == 'a')
	{
		if (stack->head->value == max && stack->head->next->value == min)
			sa(stack, &dump);
		return ;
	}
	if (type == 'b')
		if (stack->head->value == min && stack->head->next->value == max)
			sb(stack, &dump);
}

void	sort_3_nodes(t_stack *stack, int type)
{
	t_node	*node;
	int		max;
	int		min;
	int		dump;

	if (stack->size != 3)
		return ;
	node = stack->head;
	min = get_min(node);
	max = get_max(node);
	while (type == 'a' && !is_sorted(stack, type))
		if ((node->value == min && node->next->value == max) ||
			(node->next->value == min && node->next->next->value == max) ||
			(node->value == max && node->next->next->value == min))
			sa(stack, &dump);
		else if (node->next->value == max && node->next->next->value == min)
			rra(stack);
		else if (node->value ==  max && node->next->value == min)
			ra(stack, &dump);
	while (type == 'b' && !is_sorted(stack, type))
		if ((node->value == min && node->next->next->value == max) ||
			(node->next->value == max && node->next->next->value == min) ||
			(node->value == max && node->next->value == min))
			sb(stack, &dump);
		else if (node->next->value == min && node->next->next->value == max)
			rrb(stack);
		else if (node->value == min && node->next->value== max)
			rb(stack, &dump);
}
