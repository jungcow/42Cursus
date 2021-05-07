/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 06:05:34 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/07 17:19:47 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H

# define TERM_NAME "imposter-1.0$ "

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
	char			*cm;
	char			*im;
	char			*ei;
	char			*cd;
	char			*ce;
	char			*dc;
}					t_cp;

typedef struct		s_term
{
	const char		*name;
	struct termios	save_term;
	struct termios	new_term;
	t_cp			cp;
	t_pos			pos;
}					t_term;

int					tputs_wrapper(int tc);
int					init_termcap(t_cp *capability);
void				init_terminal(t_term *term);
void				run_minishell(char **env);
void				init_signal(void);
void				sigquit_handler(void);
void				sigint_handler(void);
void				print_ascii_art(void);

#endif
