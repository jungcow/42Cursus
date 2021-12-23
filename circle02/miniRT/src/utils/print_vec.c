/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:28:59 by jungwkim          #+#    #+#             */
/*   Updated: 2021/04/06 21:16:02 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

void	print_vec(t_vec vec, char *str)
{
	printf("%s : (%lf, %lf, %lf)\n", str, vec.x, vec.y, vec.z);
}
