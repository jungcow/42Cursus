/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 03:02:05 by jungwkim          #+#    #+#             */
/*   Updated: 2021/05/28 18:19:24 by jungwkim         ###   ########.fr       */
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
/*	fd2 = open(file2, O_WRONLY);
	if (fd2 < 0)
	{
		close(fd1);
		return (2);
	}
	close(fd2);
	*/
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
//	else if (ret == 2)
//		return (ft_error_str(NO_FILE_ERR, argv[argc - 1]));
	return (1);
}
