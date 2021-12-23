/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:47:09 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/21 17:09:55 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

int		get_min(t_node *node, int time)
{
	int		min;
	t_node	*tmp;

	if (!node)
		return (0);
	min = node->value;
	tmp = node;
	while (tmp && time--)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int		get_max(t_node *node, int time)
{
	int		max;
	t_node	*tmp;

	if (!node)
		return (0);
	max = node->value;
	tmp = node;
	while (tmp && time--)
	{
		if (max < tmp->value)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}
