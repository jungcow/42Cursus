/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:44:04 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/07 03:56:44 by jungwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATE_H
# define SIMULATE_H

# define UNSIGNED_INT_MAX 4294967295
# define TIME_UNIT 1000

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"

# define THINKING 0
# define EATING 1
# define SLEEPING 2
# define FORK 3
# define DEAD 4

# define TAKE 0
# define PUT 1

# define LIVE 0
# define DEAD 4

# define DEATH_TIMER_OFF 0
# define DEATH_TIMER_ON 1
# define DEATH_TIMER_DONE -1

# define NOT_CONFIRMED 0
# define CONFIRMED 10

# define SIMUL_DONE 4

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
	pthread_mutex_t	*timer_mutex;
	pthread_mutex_t	*confirm_mutex;
	pthread_mutex_t	clock_mutex;
	pthread_mutex_t	philo_mutex;
	pthread_mutex_t	philo_id_mutex;
	pthread_mutex_t	monitor_id_mutex;
	pthread_mutex_t	elapsed_mutex;
}					t_mutex;

typedef struct s_shared
{
	int			*timer_status;
	int			*confirmed;
	int			clock_status;
	int			philo_status;
	t_uint64	elapsed_time;
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
t_uint64	get_time(void);

/*
**		utils_for_check_timer
*/
int			check_elapsed_timer(t_simul *simul);
int			check_timer_keepgoing(t_simul *simul,
				t_uint64 time, t_uint64 start);
int			check_death_timer_on(t_simul *simul, t_philo *philo);
int			check_death_timer_off(t_simul *simul, t_philo *philo);
int			check_timer_off_confirmed(t_simul *simul, t_philo *philo);
int			check_monitoring(t_simul *simul, t_philo *philo);
int			check_philo_died(t_simul *simul);

void		print_mutex(t_simul *simul, int philo_idx, int purpose);

#endif
