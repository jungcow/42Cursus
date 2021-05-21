/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:57:23 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/21 04:02:52 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "libft.h"

int		get_pivot(t_stack *stack, int *pivot, int time, int constant)
{
	t_node	*node;
	t_node	*ptr;
	int		num;
	int		value;
	int		i;
	int		j;

	node = stack->head;
	*pivot = get_max(node);
	i = 0;
	while (node && i++ < time)
	{
		num = 0;
		value = node->value;
		ptr = stack->head;
		j = 0;
		while (ptr && j++ < time)
		{
			if (value > ptr->value)
				num += 1;
			ptr = ptr->next;
		}
		if (num >= constant * time / 3 && num <= constant * time / 2)
			if (value < *pivot)
				*pivot = value;
		node = node->next;
	}
	return (1);
}
