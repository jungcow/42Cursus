/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 03:41:09 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/27 04:30:58 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# define READ	0
# define WRITE	1

typedef struct		s_execute
{
	char			*input;
	char			*output;
	char			***command;
	int				input_fd;
	int				output_fd;
	int				num;
}					t_execute;

#endif
