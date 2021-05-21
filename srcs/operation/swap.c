/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:46:00 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/22 01:37:24 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "operation.h"

void	swap_node(t_node *node1, t_node *node2)
{
	int		tmp;

	tmp = node1->value;
	node1->value = node2->value;
	node2->value = tmp;
}

void	sa(t_stack *stack, int *sa, int flag)
{
	*sa += 1;
	if (stack->size <= 1)
		return ;
	swap_node(stack->head, stack->head->next);
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack, int *sb, int flag)
{
	*sb += 1;
	if (stack->size <= 1)
		return ;
	swap_node(stack->head, stack->head->next);
	if (flag)
		write(1, "sb\n", 3);
}

void	ss(t_pair *pair, int flag)
{
	if (pair->a.size <= 1 && pair->b.size <= 1)
		return ;
	if (pair->a.size > 1)
		swap_node(pair->a.head, pair->a.head->next);
	if (pair->b.size > 1)
		swap_node(pair->b.head, pair->b.head->next);
	if (flag)
		write(1, "ss\n", 3);
}
