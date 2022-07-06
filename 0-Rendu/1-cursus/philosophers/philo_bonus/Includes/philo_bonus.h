/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:35:40 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/05/17 18:36:06 by mdoquocb         ###   ########.ca       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdbool.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <libft.h>
# include <signal.h>

# define THINK		1
# define ONE_FORK	2
# define TWO_FORK	3
# define EAT		4
# define SLEEP		5
# define DEAD		6
# define DONE		7

typedef struct s_philo	t_philo;

typedef struct s_global
{
	long long		start_time;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	t_philo			**philo;
	sem_t			*check;
	sem_t			*priority;
	sem_t			*forks;
	sem_t			*prints;
}				t_global;

typedef struct s_philo
{
	pid_t			pid_id;
	pthread_t		thread_id;
	int				philo_id;
	int				statut;
	long long		last_meal_timestamp;
	int				number_eat;
	t_global		*global;
}				t_philo;

	//1_init_global.c
int			init_philo(t_global **global);	
int			fill_data(char *argv);
int			init_global(t_global **global, char **argv);

	//2_start_philo.c
void		*start_time(void *global_void);
void		loop_philo(void *philo_void);
void		start_philo(t_global *global);

	//3_utils_philo.c
void		two_fork(t_global	*global, int philo_id);
void		one_fork(t_global	*global, int philo_id);
void		eat_philo(t_philo *philo);
void		sleep_philo(t_philo *philo);
void		free_fork(t_global	*global);

	//4_end_philo.c
void		sleep_check(t_philo *philo);
void		*loop_healt(void *philo_void);
int			wait_philo(t_global *global);

	//5_put_philo.c
void		put_success(t_philo *philo);
int			put_error(int flag);
int			put_philo(t_philo *philo, int flag);
int			free_philo(t_global	*global, int error);
int			free_philo_2(t_global *global, int flag);

#endif
