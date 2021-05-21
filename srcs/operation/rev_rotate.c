/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 22:23:42 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/21 03:13:20 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "operation.h"

int		rev_rotate_node(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->next = stack->head;
	tmp->prev = NULL;
	stack->head->prev = tmp;
	stack->head = tmp;
	return (1);
}

void	rra(t_stack *stack)
{
	if (stack->size <= 1)
		return ;
	rev_rotate_node(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	if (stack->size <= 1)
		return ;
	rev_rotate_node(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_pair *pair)
{
	if (pair->a.size <= 1 && pair->b.size <= 1)
		return ;
	if (pair->a.size > 1)
		rev_rotate_node(&pair->a);
	if (pair->b.size > 1)
		rev_rotate_node(&pair->b);
	write(1, "rrr\n", 4);
}
