/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:39:16 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/19 20:35:28 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "libft.h"

typedef struct			s_history
{
	t_string			line;
	t_string			temp;
	int					length;
	int					cursor;
	int					num;
//	int					fd;
	struct s_history	*next;
	struct s_history	*before;
}						t_history;

int		init_history(t_history **head, t_history **new, char *line);
int		parse_history(int *history_fd, t_history **head);
void	clear_history(t_history **head);
void	get_history(t_history **ptr, int *bottom, int *flag, int key);

#endif
