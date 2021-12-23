/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:50:17 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/22 00:22:08 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
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

void	pa(t_pair *pair, int *pa, int flag)
{
	*pa += 1;
	if (pair->b.size <= 0)
		return ;
	push_stack(&pair->a, &pair->b);
	if (flag)
		write(1, "pa\n", 3);
	pair->a.size++;
	pair->b.size--;
}

void	pb(t_pair *pair, int *pb, int flag)
{
	*pb += 1;
	if (pair->a.size <= 0)
		return ;
	push_stack(&pair->b, &pair->a);
	if (flag)
		write(1, "pb\n", 3);
	pair->b.size++;
	pair->a.size--;
}
