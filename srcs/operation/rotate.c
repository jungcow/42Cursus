/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:59:51 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/18 21:40:02 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "operation.h"

int		rotate_node(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = stack->head;
	stack->head = stack->head->next;
	stack->head->prev = NULL;
	tmp->next->next = NULL;
	return (1);
}

int		rotate_a(t_stack *a)
{
	if (a->size <= 1)
		return (0);
	rotate_node(a);
	return (1);
}

int		rotate_b(t_stack *b)
{
	if (b->size <= 1)
		return (0);
	rotate_node(b);
	return (1);
}

int		rotate_ab(t_pair *pair)
{
	if (a->size > 1)
		rotate_node(a);
	if (b->size > 1)
		rotate_node(b);
	return (1);
}
