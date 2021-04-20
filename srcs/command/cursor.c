/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:50:41 by seunghoh          #+#    #+#             */
/*   Updated: 2021/04/19 20:36:37 by jungwkim         ###   ########.fr       */
/*   Updated: 2021/04/19 16:13:53 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <termcap.h>
#include "command/command.h"

int		apply_cursor_key(t_command *command, t_term *term, int key)
{
	char	ch;

	init_term_size(command, term);
	get_cursor_pos(term);
	if (((*command->command_line)->cursor > 0) && key == LEFT_ARROW)
	{
		delete_string(&command->line, command->line.length - 1, &ch);
		if (!add_string(&command->temp, 0, ch))
			return (-1);
		command->cursor--;
		write(1, &key, sizeof(key));
	}
	else if ((command->cursor < command->length) && key == RIGHT_ARROW)
	{
		delete_string(&command->temp, 0, &ch);
		if (!add_string(&command->line, command->line.length, ch))
			return (-1);
		command->cursor++;
		if (term->pos.cur_col == term->pos.col - 1)
			tputs(tgoto(term->cap.cm, 0, ++term->pos.cur_row),
													1, tputs_wrapper);
		else
			write(1, &key, sizeof(key));
	}
	return (1);
}

int		apply_history_key(t_command *command, t_term *term, int key)
{
	static t_history	**ptr;
	static int			bottom;
	int					flag;

	ptr = command->head;
	flag = 0;
	if (*(command->head) == NULL)
		write_historyline(command, term, "", 2);
	else
	{
		get_history(ptr, &bottom, &flag, key);
		write_historyline(command, term, (*ptr)->str, flag);
	}
	return (1);
}

int		apply_delete_key(t_command *command, t_term *term)
{
	char	dump;

	if (command->length <= 0)
		return (1);
	if (apply_cursor_key(command, term, LEFT_ARROW) == -1)
		return (-1);
	delete_string(&command->temp, 0, &dump);
	tputs(term->cap.dc, 1, tputs_wrapper);
	refresh_command(command, term);
	command->length--;
	return (1);
}
