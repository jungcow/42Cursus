/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 03:24:45 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/27 14:40:56 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define NO_FILE_ERR	"No such file or directory"
# define PERMISSION_ERR "Permission denied"
# define COMMAND_ERR	"command not found"

int		ft_error(char *str);
int		ft_error_str(char *str, char *cause);

#endif
