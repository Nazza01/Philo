/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   died.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:11:33 by Nathanael         #+#    #+#             */
/*   Updated: 2022/05/30 14:46:18 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief	Checks the current philosopher if it has died according to when it
 * last ate, and time to die. Also locks and prints the current philo when it
 * dies.
 * @param	prog	The program struct
 * @param	philo	The current philosopher
 * @return	Returns and frees the current philo
**/
void	check_died(t_prog *prog, t_philo *philo)
{
	int	index;

	index = 0;
	while (1)
	{
		if (philo[index].prog->total_eat == philo[index].prog->num_philo)
		{
			delete_mut(philo);
			ph_free(prog, philo, philo->mut);
			return ;
		}
		if (t_ms() - philo[index].ms_last_eat > (unsigned long) prog->time_die)
		{
			usleep(100);
			pthread_mutex_lock(philo->pr_lock);
			printf("%lums %d died\n", t_ms() - prog->start_time, philo->id);
			delete_mut(philo);
			ph_free(prog, philo, philo->mut);
			return ;
		}
	}
	index = (index + 1) % prog->num_philo;
	usleep(500);
}
