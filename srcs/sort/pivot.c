/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:57:23 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/22 02:05:33 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "libft.h"

int		get_pivot_utils(t_stack *stack, int value, int time)
{
	t_node	*ptr;
	int		num;
	int		j;

	num = 0;
	ptr = stack->head;
	j = 0;
	while (ptr && j++ < time)
	{
		if (value > ptr->value)
			num += 1;
		ptr = ptr->next;
	}
	return (num);
}

int		get_pivot(t_stack *stack, int *pivot, int time, float constant)
{
	t_node	*node;
	int		num;
	int		value;
	int		i;

	node = stack->head;
	*pivot = get_max(node, stack->size);
	i = 0;
	while (node && i++ < time)
	{
		value = node->value;
		num = get_pivot_utils(stack, value, time);
		if (num >= constant * time / 3 && num <= constant * time / 2)
			if (value < *pivot)
				*pivot = value;
		node = node->next;
	}
	return (1);
}
