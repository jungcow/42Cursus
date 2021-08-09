/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:44:04 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/09 15:26:25 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATE_H
# define SIMULATE_H

# define UNSIGNED_INT_MAX 4294967295
# define TIME_UNIT 1000

# define THINKING 0
# define EATING 1
# define SLEEPING 2
# define FORK 3
# define DEAD 4

# define TAKE 0
# define PUT 1

# define LIVE 0
# define DEAD 4

# define DONE 2

# define CLOCK_NOT_START 0
# define CLOCK_START 1
# define CLOCK_TERMINATE 4

# include <pthread.h>

typedef unsigned long long	t_uint64;

typedef struct s_info
{
	int			philo_num;
	t_uint64	time_to_die;
	t_uint64	time_to_eat;
	t_uint64	time_to_sleep;
	t_uint64	max_eat_num;
}				t_info;

typedef struct s_philo
{
	int		index;
	int		lfork;
	int		rfork;
}			t_philo;

typedef struct s_mutex
{
	pthread_mutex_t	record;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*start_mutex;
	pthread_mutex_t	*simul_mutex;
	pthread_mutex_t	philo_mutex;
	pthread_mutex_t	philo_id_mutex;
	pthread_mutex_t	monitor_id_mutex;
}					t_mutex;

typedef struct s_shared
{
	t_uint64	*start_time;
	t_uint64	elapsed_time;
	int			clock_status;
	int			philo_status;
	int			*simul_status;
}				t_shared;

typedef struct s_simul
{
	int				index;
	int				monitor_index;
	pthread_t		*philo_ids;
	pthread_t		*monitor_ids;
	pthread_t		clock_id;
	t_info			info;
	t_philo			*philo;
	t_mutex			mutex;
	t_shared		shared;
}					t_simul;

/*
**		main_simulation_function
*/
int			simulate(int argc, char **argv);
int			init_simulation(t_simul *simul, int argc, char **argv);
int			exec_simulation(t_simul *simul);
void		clear_simulation(t_simul *simul);
void		*philosopher(void *param);
void		*monitoring(void *param);
void		*elapsed_timer(void *param);

/*
**		utils_for_simulation
*/
void		ft_sleep(t_uint64 time, t_simul *simul);
int			check_philo_died(t_simul *simul);
void		print_mutex(t_simul *simul, int philo_idx, int purpose);

#endif
