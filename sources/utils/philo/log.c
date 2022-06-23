/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:36:37 by Nathanael         #+#    #+#             */
/*   Updated: 2022/05/30 14:10:45 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief	Outputs what a philosopher is doing at the current time. Locks the
 * printing state using the pr_lock variable so only a specific philosopher
 * is able to output at once.
 * @param	philo	The philosopher struct
 * @param	current	The current time in milliseconds
 * @param	msg		The message to print
**/
void	ph_log(t_philo *philo, long long current, char *msg)
{
	pthread_mutex_lock(philo->pr_lock);
	printf("%llims %d %s\n", current, philo->id, msg);
	pthread_mutex_unlock(philo->pr_lock);
}
