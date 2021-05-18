/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:07:59 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/16 18:27:17 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_H
# define CREATE_H

typedef struct		s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	int				size;
	t_node			*head;
}					t_stack;

typedef struct		s_pair
{
	t_stack			a;
	t_stack			b;
}					t_pair;

int					create_stack(int argc, char ***buf, t_pair *pair);
void				clear_stack(t_stack *stack);

#endif
