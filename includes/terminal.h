/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 06:05:34 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/20 23:06:37 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H

# include <termios.h>
# include <curses.h>

typedef struct		s_pos
{
	int				col;
	int				row;
	int				cur_col;
	int				cur_row;
}					t_pos;

typedef struct		s_cp
{
	char			*cm; //move curser
	char			*im; //turn on insert mode
	char			*ei; //turn off insert mode (actually, it is switch)
	char			*cd; // delete all lines below the cursor
	char			*ce; // delete all characters before cursor(one line)
	char			*dc; // delete one characters at cursors
}					t_cp;

typedef struct		s_term
{
	const char		*name;
	struct termios	save_term;
	t_cp			cp;
	t_pos			pos;
}					t_term;

int					tputs_wrapper(int tc);
int					get_cursor_pos(t_term *term);

#endif
