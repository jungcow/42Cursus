/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:20:22 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/04 22:02:35 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define MEMORY_ERR					"Error on Memory Allocation."

# define MUTEX_INIT_EINVAL_ERR		"The value specified by attr is invalid."
# define MUTEX_INIT_ENOMEM_ERR		"Memory is not enough to create mutex."

# define PTHREAD_CREATE_EAGAIN_ERR	"Lacked the necessary resources to create." 
# define PTHREAD_CREATE_EPERM_ERR	"Don't have permission to set scheduling."
# define PTHREAD_CREATE_EINVAL_ERR	"The value specified by attr is invalid."

# define PTHREAD_JOIN_EINVAL_ERR	"Thread doesn't refer to a joinable thread."
# define PTHREAD_JOIN_ESRCH_ERR		"No thread could be found corresponding." 
# define PTHREAD_JOIN_EDEADLK_ERR	"A deadlock was detected."

# define MUTEX_DESTROY_EINVAL_ERR	"The value specified by mutex is invalid."
# define MUTEX_DESTROY_EBUSY_ERR	"Mutex is locked."

void	show_error(int err_num);

#endif
