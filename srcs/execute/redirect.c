/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:59:23 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/27 19:12:14 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "error.h"
#include "execute.h"

int		input_redirection(t_execute *execute)
{
	close(READ);
	execute->input_fd = open(execute->input, O_RDONLY);
	if (execute->input_fd < 0)
		return (ft_error_str(PERMISSION_ERR, execute->input));
	return (1);
}

int		output_redirection(t_execute *execute)
{
	close(WRITE);
	execute->output_fd = open(execute->output, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (execute->output_fd < 0)
		return (ft_error_str(PERMISSION_ERR, execute->output));
	return (1);
}
