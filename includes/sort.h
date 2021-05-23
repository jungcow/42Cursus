/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:24:23 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/23 16:32:40 by jungwkim         ###   ########.fr       */
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

void			a_to_b(t_pair *pair, int time);
void			b_to_a(t_pair *pair, int time);

int				sort_23_nodes(t_pair *pair, t_stack *stack, int type);
int				sort_23_times(t_pair *pair, int time, int type);
int				sort_few_times(t_pair *pair, int time, int type);
void			sort_few_times_a(t_pair *pair, int time);
void			sort_few_times_b(t_pair *pair, int time);

int				is_sorted(t_stack *stack, int type, int time);

int				pre_sort(t_pair *pair, int time, int type);

void			init_sort(t_stack *stack, int *pivot, int t, t_operation *op);

int				get_pivot(t_stack *stack, int *pivot, int time, float constant);
int				get_direction(t_stack *stack, int pivot, int time, int type);
int				get_min(t_node *node, int time);
int				get_max(t_node *node, int time);

#endif
