/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:20:22 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/10 07:28:05 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ARG_ERR_NUM -2
# define ARG_ERR					"ERROR: Invalid Arguments"
# define USAGE "usage: \n./philo [time_to_die] [time_to_sleep] [time_to_eat] "
# define USAGE2	"([max_eat_number])\n [max_eat_number] is optional.\n"
# define CAUSE " Warning: All Arguments should not to Negative!\n"

# define MEMORY_ERR					"Error on System(e.g. Memory Allocation.)"

# define PTHREAD_CREATE_EAGAIN_ERR	"Lacked the necessary resources to create." 
# define PTHREAD_CREATE_EPERM_ERR	"Don't have permission to set scheduling."
# define PTHREAD_CREATE_EINVAL_ERR	"The value specified by attr is invalid."

# define PTHREAD_JOIN_EINVAL_ERR	"Thread doesn't refer to a joinable thread."
# define PTHREAD_JOIN_ESRCH_ERR		"No thread could be found corresponding." 
# define PTHREAD_JOIN_EDEADLK_ERR	"A deadlock was detected."

void	show_error(int err_num);

#endif
