/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 03:02:05 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/28 21:59:10 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "validate.h"
#include "error.h"

int		validate_filename(char *file1)
{
	int		fd1;

	fd1 = open(file1, O_RDONLY);
	if (fd1 < 0)
		return (1);
	close(fd1);
	return (0);
}

int		validate(int argc, char *argv[])
{
	int		ret;

	if (argc < 5)
		return (ft_error("Argument number error"));
	ret = validate_filename(argv[1]);
	if (ret == 1)
		return (ft_error_str(NO_FILE_ERR, argv[1]));
	return (1);
}
