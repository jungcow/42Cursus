/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:18:05 by seunghoh          #+#    #+#             */
/*   Updated: 2021/04/16 17:14:59 by seunghoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termios.h>
#include <termcap.h>
#include <curses.h>
#include "libft.h"
#include "command/command.h"

static int		putchar_tc(int tc)
{
	write(1, &tc, 1);
	return (0);
}

void	init_minishell()
{
	struct termios	term;
	char			*im;
	
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON;
    term.c_lflag &= ~ECHO;
    term.c_cc[VMIN] = 1;
    term.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
	tgetent(NULL, "xterm");
	im = tgetstr("im", NULL);
	tputs(im, 1, putchar_tc);
}

void	run_minishell()
{
	t_command	command;
	
	init_minishell();
	// error
	if (!init_command(&command))
		return ;
	read_command(&command);
	clear_command(&command);
}

int		main()
{
	run_minishell();
	system("leaks minishell");
	return (0);
}
