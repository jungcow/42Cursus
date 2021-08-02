/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:44:04 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/02 11:52:53 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATE_H
# define SIMULATE_H

# define UNSITEND_INT_MAX 4294967295
# define TIME_UNIT
# define THINKING 0
# define START_EATING 1
# define START_SLEEPING 2
# define DIED 4
# define TIMER_OFF 10
# define TIMER_ON 11

# include <pthread.h>

typedef struct s_info
{
	int			philo_num;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	long long	max_eat_num;
}				t_info;

typedef struct s_philo
{
	int		lfork;
	int		rfork;
}			t_philo;

typedef struct s_mutex
{
	pthread_mutex_t	*forks;
	pthread_mutex_t simul_index;
}					t_mutex;

typedef struct s_shared
{
	int	*status; // philo마다 status한개씩갖는다.
	int	simul_num;
	int elapsed_time;
	int	is_death;
}		t_shared

typedef struct s_simul
{
	int				index;
	pthread_t		*philo_ids;
	pthread_t		*timer_ids;
	t_info			info; // to eat, sleep, need philo_num
	t_philo			*philo;
	t_mutex			mutex;
	t_shared		shared;
}					t_simul;

int	simulate(int argc, char **argv);
int	start_simulation(t_simul *simul);

#endif
