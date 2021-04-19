/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 06:05:34 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/19 11:46:45 by seunghoh         ###   ########.fr       */
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

typedef struct		s_cap
{
	char			*cm; //move curser
	char			*im; //turn on insert mode
	char			*ei; //turn off insert mode (actually, it is switch)
	char			*cd; // delete all lines below the cursor
	char			*ce; // delete all characters before cursor
	char			*dc; // delete one characters at cursors
}					t_cap;

typedef struct		s_term
{
	struct termios	save_term;
	t_cap			cap;
	t_pos			pos;
	const char		*name;
}					t_term;

int					get_cursor_pos(t_term *term);

#endif
