/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:46:00 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/21 02:59:48 by jungwkim         ###   ########.fr       */
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

void	sa(t_stack *stack, int *sa)
{
	*sa += 1;
	if (stack->size <= 1)
		return ;
	swap_node(stack->head, stack->head->next);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack, int *sb)
{
	*sb += 1;
	if (stack->size <= 1)
		return ;
	swap_node(stack->head, stack->head->next);
	write(1, "sb\n", 3);
}

void	ss(t_pair *pair)
{
	if (pair->a.size <= 1 && pair->b.size <= 1)
		return ;
	if (pair->a.size > 1)
		swap_node(pair->a.head, pair->a.head->next);
	if (pair->b.size > 1)
		swap_node(pair->b.head, pair->b.head->next);
	write(1, "ss\n", 3);
}
