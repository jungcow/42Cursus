/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:48:51 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/21 03:00:28 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

# include "create.h"

void		sa(t_stack *stack, int *sa);
void		sb(t_stack *stack, int *sb);
void		ss(t_pair *pair);

void		pa(t_pair *pair, int *pa);
void		pb(t_pair *pair, int *pb);

void		ra(t_stack *stack, int *ra);
void		rb(t_stack *stack, int *rb);
void		rr(t_pair *pair);

void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_pair *pair);

#endif
