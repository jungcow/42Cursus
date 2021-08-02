/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:37:54 by jungwkim          #+#    #+#             */
/*   Updated: 2021/07/13 17:39:44 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	validate_arguments(int argc, char **argv)
{
	if (!(argc == 5 || argc == 6))
		return (0);
	//time_to_eat, time_to_sleep, time_to_die, number_of_times_each_philosopher_must_eat 이 0이어도 되나? 시뮬레이션에서 자동으로 처리가 되나?
	if (ft_atoi(argv[1]) <= 0)
		return (0);
	if (ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (0);
	if (argc == 6 && ft_atoi(argv[5]) < 0)
		return (0);
	return (1);
}
