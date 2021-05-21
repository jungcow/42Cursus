/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:42:36 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/21 03:11:20 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "libft.h"

int		search_before_pivot(t_node **node, int pivot, int time, int type)
{
	int		num;

	num = 0;
	while (*node && time--)
	{
		if (pivot == (*node)->value)
			break ;
		if (type == 'a')
		{
			if (pivot > (*node)->value)
				num++;
		}
		else if (type == 'b')
		{
			if (pivot < (*node)->value)
				num++;
		}
		*node = (*node)->next;
	}
	return (num);
}

int		search_after_pivot(t_node **node, int pivot, int time, int type)
{
	int		num;

	num = 0;
	while (*node && time--)
	{
		if (type == 'a')
		{
			if (pivot > (*node)->value)
				num++;
		}
		else if (type == 'b')
		{
			if (pivot < (*node)->value)
				num++;
		}
		*node = (*node)->next;
	}
	return (num);
}

int		get_direction(t_stack *stack, int pivot, int time, int type)
{
	t_node	*node;
	int		num;

	node = stack->head;
	num = search_before_pivot(&node, pivot, time, type);
	if (num < search_after_pivot(&node, pivot, time, type))
		return (1);
	return (0);
}
