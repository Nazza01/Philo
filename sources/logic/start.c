/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:59:50 by Nathanael         #+#    #+#             */
/*   Updated: 2022/05/30 14:11:06 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief	Thread creation called from pthread_create, lock and unlocks using
 * mutex locks while printing actions relevent to each philosopher
 * @param	void_philo	The arguments that are passed from pthread_create funct
 * @return	EXIT_SUCCESS up successful execution
**/
void	*ph_start(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (philo->id % 2 == 0)
		usleep(1);
	philo->ms_last_eat = t_ms();
	while (1)
	{
		pthread_mutex_lock(&philo->mut[philo->id - 1]);
		ph_log(philo, t_diff(philo), "has taken a fork");
		pthread_mutex_lock(&philo->mut[philo->id % philo->prog->num_philo]);
		ph_log(philo, t_diff(philo), "has taken a fork");
		ph_log(philo, t_diff(philo), "is eating");
		philo->ate++;
		if (philo->ate == philo->prog->must_eat)
			philo->prog->total_eat++;
		philo->ms_last_eat = t_ms();
		usleep(philo->prog->time_eat * 1000);
		pthread_mutex_unlock(&philo->mut[philo->id - 1]);
		pthread_mutex_unlock(&philo->mut[philo->id % philo->prog->num_philo]);
		ph_log(philo, t_diff(philo), "is sleeping");
		usleep(philo->prog->time_sleep * 1000);
		ph_log(philo, t_diff(philo), "is thinking");
	}
	return (EXIT_SUCCESS);
}
