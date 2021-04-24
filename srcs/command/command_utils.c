/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 00:12:35 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/24 21:24:38 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdbool.h>
#include "command/command.h"

int			load_command(t_command *command, char *str, int bell)
{
	int		i;

	if (bell == 1 || bell == 2)
		write(0, "\a", 1);
	if (command->command_status == false && str == NULL)
		return (1);
	i = -1;
	if (command->command_status == false)
	{
		while (++i < (int)ft_strlen(str))
			if (!add_string(&command->line, command->line.length, str[i]))
				return (0);
	}
	else
	{
		while (++i < (int)ft_strlen(command->ptr->str))
			if (!add_string(&command->line, command->line.length,
											command->ptr->str[i]))
				return (0);
	}
	command->length = command->line.length;
	command->cursor = command->line.length;
	write(1, command->line.content, command->line.length);
	return (1);
}

int			change_command(t_command *command, int key)
{
	if (key == UP_ARROW)
	{
		if (command->command_status == false && command->ptr)
			command->command_status = true;
		else if (command->command_status && command->ptr
										&& command->ptr->before)
			command->ptr = command->ptr->before;
		else
			return (1);
	}
	else if (key == DOWN_ARROW)
	{
		if (command->command_status && command->ptr && command->ptr->next)
			command->ptr = command->ptr->next;
		else
		{
			if (command->command_status)
				command->command_status = false;
			return (2);
		}
	}
	return (0);
}

int			save_command(t_command *command, char **str)
{
	if (command->command_status == true)
	{
		free(command->ptr->str);
		command->ptr->str = ft_strndup(command->line.content,
											command->line.length);
		if (command->ptr->str == NULL)
			return (0);
	}
	else
	{
		free(*str);
		*str = ft_strndup(command->line.content, command->line.length);
		if (*str == NULL)
			return (0);
	}
	return (1);
}

void		refresh_command(t_command *command, t_term *term)
{
	int		i;
	int		key;

	i = 0;
	tputs(term->cp.cd, 1, tputs_wrapper);
	if (command->temp.length > 0)
	{
		key = LEFT_ARROW;
		while (i < command->temp.length)
		{
			write(1, command->temp.content + i, 1);
			i++;
		}
		i = 0;
		while (i < command->temp.length)
		{
			write(1, &key, sizeof(key));
			++i;
		}
	}
}
