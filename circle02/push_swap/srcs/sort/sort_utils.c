/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:31:31 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/25 17:40:03 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operation.h"

void	sorting(t_pair *pair, int *pivot, t_operation *op, int type)
{
	if (type == 'a')
	{
		if (pair->a.head->value > pivot[1])
			ra(&pair->a, &op->ra, 1);
		else
		{
			pb(pair, &op->pb, 1);
			if (pair->b.head->value > pivot[0])
				rb(&pair->b, &op->rb, 1);
		}
	}
	else if (type == 'b')
	{
		if (pair->b.head->value < pivot[0])
			rb(&pair->b, &op->rb, 1);
		else
		{
			pa(pair, &op->pa, 1);
			if (pair->a.head->value < pivot[1])
				ra(&pair->a, &op->ra, 1);
		}
	}
}
