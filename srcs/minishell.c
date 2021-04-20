/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:18:05 by seunghoh          #+#    #+#             */
/*   Updated: 2021/04/20 23:28:37 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termios.h>
#include <termcap.h>
#include <curses.h>
#include <stdlib.h>
#include "libft.h"
#include "terminal.h"
#include "command/command.h"

int		tputs_wrapper(int tc)
{
	write(1, &tc, 1);
	return (0);
}

int		init_termcap(t_cp *capability)
{
	char	*termtype;

	termtype = getenv("TERM");
	if (termtype == NULL)
		return (0);
	tgetent(NULL, termtype);
	capability->cm = tgetstr("cm", NULL);
	capability->im = tgetstr("im", NULL);
	capability->ei = tgetstr("ei", NULL);
	capability->cd = tgetstr("cd", NULL);
	capability->ce = tgetstr("ce", NULL);
	capability->dc = tgetstr("dc", NULL);
	tputs(capability->im, 1, tputs_wrapper);
	return (1);
}

int		init_minishell(t_term *term)
{
	struct termios	new_term;

	if (!init_termcap(&term->cp))
		return (0);
	tcgetattr(STDIN_FILENO, &term->save_term);
	new_term = term->save_term;
	new_term.c_lflag &= ~ICANON;
	new_term.c_lflag &= ~ECHO;
	new_term.c_cc[VMIN] = 1;
	new_term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
	return (1);
}

void	run_minishell(void)
{
	t_term		term;
	t_command	command;
	t_history	*head;

	term.name = "seung-jung$>";
	if (!init_minishell(&term))
		return ;
	// error
	if (!init_command(&command, &head))
		return ;
	read_command(&command, &term);
	clear_command(&command);
	tputs(term.cp.ei, 1, tputs_wrapper);
	tcsetattr(STDIN_FILENO, TCSANOW, &term.save_term);
}

int		main(void)
{
	run_minishell();
	system("leaks minishell");
	return (0);
}
