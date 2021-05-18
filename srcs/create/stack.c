/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:05:41 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/16 23:41:28 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create.h"
#include "libft.h"

#include <stdio.h>
int		init_node(t_node **head, char *buf)
{
	t_node	*new;
	t_node	*ptr;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		exit(-1);
	new->prev = NULL;
	new->next = NULL;
	new->value = ft_atoi(buf);
	if (*head == NULL)
		*head = new;
	else if (*head)
	{
		ptr = *head;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
	}
	return (1);
}

int		init_stack(t_stack *stack, char ***buf)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = 0;
	stack->head = NULL;
	i = -1;
	while (buf && buf[++i])
	{
		j = -1;
		while (buf[i][++j])
		{
			size++;
			init_node(&stack->head, buf[i][j]);
		}
	}
	stack->size = size;
	return (1);
}

int		create_stack(int argc, char ***buf, t_pair *pair)
{
	init_stack(&pair->a, buf);
	init_stack(&pair->b, buf);
	while (argc--)
		ft_strsfree(buf[argc]);
	free(buf);
	return (1);
}

void	clear_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->head;
	while (node)
	{
		tmp = node;
		node = node->prev;
		tmp->value = 0;
		tmp->prev = NULL;
		tmp->next = NULL;
		free(tmp);
	}
}
