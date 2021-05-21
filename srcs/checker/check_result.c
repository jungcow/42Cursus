/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:43:28 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/22 01:37:46 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "checker.h"
#include "libft.h"
#include "operation.h"
#include "get_next_line.h"

int		validate_operation(char *line)
{
	char	*buf[12];
	int		i;

	buf[0] = "sa";
	buf[1] = "sb";
	buf[2] = "ss";
	buf[3] = "ra";
	buf[4] = "rb";
	buf[5] = "rr";
	buf[6] = "rra";
	buf[7] = "rrb";
	buf[8] = "rrr";
	buf[9] = "pa";
	buf[10] = "pb";
	buf[11] = NULL;
	i = 0;
	while (buf[i])
	{
		if (ft_strcmp(line, buf[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		execute_operation(t_pair *pair, char *line)
{
	int		dump;

	if (!ft_strcmp(line, "sa"))
		sa(&pair->a, &dump, 0);
	else if (!ft_strcmp(line, "sb"))
		sb(&pair->b, &dump, 0);
	else if (!ft_strcmp(line, "ss"))
		ss(pair, 0);
	else if (!ft_strcmp(line, "ra"))
		ra(&pair->a, &dump, 0);
	else if (!ft_strcmp(line, "rb"))
		rb(&pair->b, &dump, 0);
	else if (!ft_strcmp(line, "rr"))
		rr(pair, 0);
	else if (!ft_strcmp(line, "rra"))
		rra(&pair->a, 0);
	else if (!ft_strcmp(line, "rrb"))
		rrb(&pair->b, 0);
	else if (!ft_strcmp(line, "rrr"))
		rrr(pair, 0);
	else if (!ft_strcmp(line, "pa"))
		pa(pair, &dump, 0);
	else if (!ft_strcmp(line, "pb"))
		pb(pair, &dump, 0);
	return (1);
}

int		check_stack(t_stack *a, t_stack *b)
{
	t_node	*node1;
	t_node	*node2;
	int		value;

	node1 = a->head;
	node2 = b->head;
	value = node1->value;
	while (node1)
	{
		if (node1->value < value)
		{
			write(1, "KO\n", 3);
			return (0);
		}
		node1 = node1->next;
	}
	if (node2 != NULL)
	{
		write(1, "KO\n", 3);
		return (0);
	}
	write(1, "OK\n", 3);
	return (1);
}

int		check_result(t_pair *pair)
{
	char	*line;

	while (get_next_line(0, &line) >= 0)
	{
		if (!line || !*line)
			break ;
		if (!validate_operation(line))
			return (0);
		execute_operation(pair, line);
		free(line);
	}
	check_stack(&pair->a, &pair->b);
	return (1);
}
