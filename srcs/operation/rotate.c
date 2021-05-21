/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:59:51 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/22 00:23:16 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
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
	stack->head->prev = tmp;
	stack->head->next->prev = NULL;
	stack->head = stack->head->next;
	tmp->next->next = NULL;
	return (1);
}

void	ra(t_stack *stack, int *ra, int flag)
{
	*ra += 1;
	if (stack->size > 1)
	{
		rotate_node(stack);
		if (flag)
			write(1, "ra\n", 3);
	}
	return ;
}

void	rb(t_stack *stack, int *rb, int flag)
{
	*rb += 1;
	if (stack->size > 1)
	{
		rotate_node(stack);
		if (flag)
			write(1, "rb\n", 3);
	}
	return ;
}

void	rr(t_pair *pair, int flag)
{
	if (pair->a.size <= 1 && pair->b.size <= 1)
		return ;
	if (pair->a.size > 1)
		rotate_node(&pair->a);
	if (pair->b.size > 1)
		rotate_node(&pair->b);
	if (flag)
		write(1, "rr\n", 3);
	return ;
}
