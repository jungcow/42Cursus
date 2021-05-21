/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:24:23 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/21 03:10:54 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "create.h"

typedef struct	s_operation
{
	int			ra;
	int			rb;
	int			pa;
	int			pb;
}				t_operation;

void	a_to_b(t_pair *pair, int time);
void	b_to_a(t_pair *pair, int time);

void	sort_2_nodes(t_stack *stack, int type);
void	sort_3_nodes(t_stack *stack, int type);

int		is_sorted(t_stack *stack, int type);

void	init_sort(t_stack *stack, int *pivot, int time, t_operation *op);

int		get_pivot(t_stack *stack, int *pivot, int time, int constant);
int		get_direction(t_stack *stack, int pivot, int time, int type);
int		get_min(t_node *node);
int		get_max(t_node *node);

#endif
