/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 03:41:09 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/27 17:02:37 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# define READ	0
# define OLD	0
# define WRITE	1
# define NEW	1

typedef struct		s_execute
{
	char			*input;
	char			*output;
	char			***command;
	int				input_fd;
	int				output_fd;
	int				num;
}					t_execute;

int					ft_execute(t_execute *execute, char *argv[]);
int					init_execution(t_execute *execute, int argc, char *argv[]);

/*
**	pipeline
*/
int					create_pipeline(int *fd, int idx);
int					treat_pipeline(t_execute *execute, int (*fd)[2], int idx);

/*
**	redirection
*/
int					input_redirection(t_execute *execute);
int					output_redirection(t_execute *execute);

/*
**	utils
*/
void				close_fds(int *fds);

#endif
