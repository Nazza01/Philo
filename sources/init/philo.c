/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:52:21 by Nathanael         #+#    #+#             */
/*   Updated: 2022/05/30 14:50:29 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief	Initialize the philosophers' struct according to the passed through
 * parameters
 * @param	prog	Program variables
 * @param	philo	The philospher to assign
 * @param	m		The thread mutex to assign
 * @param	print	The print mutex to assign
 * @return	Return Value
**/
void	init_philo(t_prog *prog, t_philo *philo, pthread_mutex_t *m, \
		pthread_mutex_t *print)
{
	int	index;

	index = 0;
	while (index < prog->num_philo)
	{
		philo[index].ate = 0;
		philo[index].id = index + 1;
		philo[index].prog = prog;
		philo[index].mut = m;
		philo[index].pr_lock = print;
		index++;
	}
}
