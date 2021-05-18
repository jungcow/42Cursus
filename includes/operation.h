/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:48:51 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/18 21:36:29 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

# include "create.h"

int		swap_a(t_stack *a);
int		swap_b(t_stack *b);
int		swap_ab(t_pair *pair);

int		push_a(t_stack *a, t_stack *b);
int		push_b(t_stack *a, t_stack *b);

int		rotate_a(t_stack *a);
int		rotate_b(t_stack *b);

#endif
