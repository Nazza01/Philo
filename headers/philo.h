/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:22:21 by Nathanael         #+#    #+#             */
/*   Updated: 2022/05/30 14:35:18 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>							//	printf
# include <pthread.h>						//	pthread_**
# include <stdlib.h>						//	malloc	free	exit
# include <unistd.h>						//	read	write
# include <sys/time.h>						//	usleep	gettimeofday
# include <string.h>						//	memset
# include <limits.h>						//	MAX_INT	MIN_INT

typedef struct s_prog
{
	int					num_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					must_eat;
	int					total_eat;
	unsigned long		start_time;
}	t_prog;

typedef struct s_philo
{
	int					ate;
	int					id;
	t_prog				*prog;
	pthread_mutex_t		*mut;
	pthread_mutex_t		*pr_lock;
	unsigned long		ms_last_eat;
}	t_philo;

/**
 * @brief	Initialization functions used in the main
 * Located in ./sources/init
**/

int				init_arg(t_prog *prog, char **av);
int				init_mutex(t_prog *prog, t_philo *philo);
void			init_philo(t_prog *prog, t_philo *philo, pthread_mutex_t *m, \
				pthread_mutex_t *print);
void			*pr_thread(t_philo *philo, unsigned long current, char *msg);

/**
 * @brief	Logic invloved between threads and philosophers
 * Located in ./sources/logic
**/

void			check_died(t_prog *prog, t_philo *philo);
void			*ph_start(void *void_philo);

/**
 * @brief	Utilities either imported or that are common to all files
 * Located in ./sources/utils
**/

int				ft_atoi(const char *str);
void			ft_error(char *msg, int code);

void			delete_mut(t_philo *philo);
int				ph_free(t_prog *prog, t_philo *philo, pthread_mutex_t *mut);
void			ph_log(t_philo *philo, long long current, char *msg);

unsigned long	t_diff(t_philo *philo);
unsigned long	t_ms(void);

#endif