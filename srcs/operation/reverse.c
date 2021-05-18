/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 22:23:42 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/18 22:23:47 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "operation.h"

int		rev_rotate_node(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
//	tmp->next = stack->head;
//	stack->head = stack->head->next;
//	stack->head->prev = NULL;
//	tmp->next->next = NULL;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = stack->head;
	stack->head->prev = tmp;
	stack->head = tmp;
	return (1);
}

int		rev_rotate_a(t_stack *a)
{
	if (a->size <= 1)
		return (0);
	rev_rotate_node(a);
	return (1);
}

int		rev_rotate_b(t_stack *b)
{
	if (b->size <= 1)
		return (0);
	rev_rotate_node(b);
	return (1);
}

int		rev_rotate_ab(t_pair *pair)
{
	if (a->size > 1)
		rev_rotate_node(a);
	if (b->size > 1)
		rev_rotate_node(b);
	return (1);
}
