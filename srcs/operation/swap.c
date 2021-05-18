/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:46:00 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/18 16:20:31 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

int		swap_node(t_node *node1, t_node *node2)
{
	int		tmp;

	tmp = node1->value;
	node1->value = node2->value;
	node2->value = tmp;
	return (1);
}

int		swap_a(t_stack *a)
{
	if (a->size > 1)
		swap_node(a->head, a->head->next);
	return (1);
}

int		swap_b(t_stack *b)
{
	if (b->size > 1)
		swap_node(b->head, b->head->next);
	return (1);
}

int		swap_ab(t_pair *pair)
{
	if (pair->a.size > 1)
		swap_node(pair->a.head, pair->a.head->next);
	if (pair->b.size > 1)
		swap_node(pair->b.head, pair->b.head->next);
	return (1);
}
