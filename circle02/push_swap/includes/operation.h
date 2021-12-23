/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:48:51 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/22 00:24:30 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

# include "create.h"

void		sa(t_stack *stack, int *sa, int flag);
void		sb(t_stack *stack, int *sb, int flag);
void		ss(t_pair *pair, int flag);

void		pa(t_pair *pair, int *pa, int flag);
void		pb(t_pair *pair, int *pb, int flag);

void		ra(t_stack *stack, int *ra, int flag);
void		rb(t_stack *stack, int *rb, int flag);
void		rr(t_pair *pair, int flag);

void		rra(t_stack *stack, int flag);
void		rrb(t_stack *stack, int flag);
void		rrr(t_pair *pair, int flag);

#endif
