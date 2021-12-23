/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungwkim <jungwkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:37:47 by jungwkim          #+#    #+#             */
/*   Updated: 2021/08/10 07:29:21 by jungwkim         ###   ########.fr       */
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

# include <semaphore.h>

typedef unsigned long long	t_uint64;
typedef struct timeval		t_time;

typedef struct s_info
{
	int			philo_num;
	t_uint64	time_to_die;
	t_uint64	time_to_eat;
	t_uint64	time_to_sleep;
	t_uint64	max_eat_num;
}				t_info;

typedef struct s_sem
{
	sem_t	*record;
	sem_t	*forks;
	sem_t	*dead;
}			t_sem;

typedef struct s_simul
{
	int				index;
	int				philo_status;
	int				simul_status;
	char			*fork_name;
	char			*record_name;
	char			*dead_name;
	pid_t			*pids;
	t_info			info;
	t_sem			sem;
	t_uint64		elapsed_time;
	t_uint64		start_time;
	t_uint64		last_eat_time;
}					t_simul;

/*
**		main_simulation_function
*/
int			simulate(int argc, char **argv);
int			init_simulation(t_simul *simul, int argc, char **argv);
int			exec_simulation(t_simul *simul);
void		clear_simulation(t_simul *simul);
int			philosopher(t_simul *simul);
void		*monitoring(void *param);

/*
**		utils_for_simulation
*/
t_uint64	get_time(void);
void		ft_sleep(t_uint64 time, t_simul *simul);
void		print_record(t_simul *simul, int philo_idx, int purpose);

#endif
