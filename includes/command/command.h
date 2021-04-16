/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoh <seunghoh@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:54:40 by seunghoh          #+#    #+#             */
/*   Updated: 2021/04/17 06:09:48 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# define BACK_SPACE 127
# define LEFT_ARROW 4479771
# define RIGHT_ARROW 4414235
# define UP_ARROW 4283163
# define DOWN_ARROW 4348699
# define QUOTE 39
# define DOUBLE_QUOTE 34
# define ENTER 10
# define CTRL_D 4

# include "libft.h"
# include "command/history.h"
# include "command/terminal.h"

typedef struct		s_command
{
	t_history		**head;
	int				history_fd;
	char			**keywords;
	int				keywords_size;
	t_string		line;
	t_string		temp;
	int				cursor;
	int				length;
}					t_command;

bool			    init_command(t_command *command, t_history **head);
int					read_command(t_command *command);
int					switch_command(t_command *command, int key);
void				clear_command(t_command *command);
int					apply_delete_key(t_command *command, int key);
int					apply_cursor_key(t_command *command, int key);
int					apply_quote_key(t_command *command, int key);
int					apply_general_key(t_command *command, int key);
int					apply_end_key(t_command *command, int key);
int					apply_history_key(t_command *command, int key);
int					tputs_wrapper(int tc);

int					add_history(t_command *command);
void				write_historyfile(t_command *command, char *num_str);
void				show_history(t_command *command, char *str, int flag);

#endif
