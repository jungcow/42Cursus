/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:50:17 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/18 21:02:23 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "operation.h"

int		push_stack(t_stack *dst, t_stack *src)
{
	t_node	*tmp;

	tmp = src->head;
	if (src->size == 1)
		src->head = src->head->next;
	else
	{
		src->head->next->prev = NULL;
		src->head = src->head->next;
	}
	tmp->next = dst->head;
	tmp->prev = NULL;
	if (dst->size > 0)
		dst->head->prev = tmp;
	dst->head = tmp;
	return (1);
}

int		push_a(t_stack *a, t_stack *b)
{
	if (b->size <= 0)
		return (0);
	push_stack(a, b);
	a->size++;
	b->size--;
	return (1);
}

int		push_b(t_stack *a, t_stack *b)
{
	if (a->size <= 0)
		return (0);
	push_stack(b, a);
	b->size++;
	a->size--;
	return (1);
}
