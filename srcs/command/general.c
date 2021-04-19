/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:10:56 by seunghoh          #+#    #+#             */
/*   Updated: 2021/04/19 16:04:31 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termcap.h>
#include "command/command.h"

int		apply_general_key(t_command *command, t_term *term, int key)
{
	if (key >= 32 && key <= 127)
	{
		if (!add_string(&command->line, command->line.length, key))
			return (-1);
		command->length++;
		command->cursor++;
		write(1, &key, 1);
		refresh_command(command, term);
	}
	return (1);
}

int		apply_quote_key(t_command *command, int key)
{
	(void) command;
	key++;
	return (1);
}
