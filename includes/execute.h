/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 03:41:09 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/28 21:58:09 by jungwkim         ###   ########.fr       */
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

int					ft_execute(t_execute *execute, char *envp[]);
int					init_execution(t_execute *execute, int argc, char *argv[]);
void				clear_execution(t_execute *execute);

/*
**	pipeline
*/
int					ft_pipe(int *fd, int index);
int					treat_pipeline(t_execute *execute,
									int *new_fd, int *old_fd, int idx);

/*
**	redirection
*/
int					input_redirection(t_execute *execute);
int					output_redirection(t_execute *execute);

/*
**	path
*/
int					get_path(char *filename, char **dir, char *envp[]);

/*
**	path_utils
*/
int					has_file(char *path, char *filename);
int					dup_str(char **env, char *str);

/*
**	environ
*/
char				*get_environ(char *env, char *envp[]);

/*
**	utils
*/
void				close_fds(int *fds);

#endif
