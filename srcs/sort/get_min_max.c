/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:47:09 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/20 16:56:27 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"

int		get_min(t_node *node)
{
	int		min;
	t_node	*tmp;

	min = 0;
	if (node)
		min = node->value;
	tmp = node;
	while (tmp)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int		get_max(t_node *node)
{
	int		max;
	t_node	*tmp;

	max = 0;
	if (node)
		max = node->value;
	tmp = node;
	while (tmp)
	{
		if (max < tmp->value)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}
