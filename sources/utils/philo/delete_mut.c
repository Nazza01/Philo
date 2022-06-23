/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_mut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:36:37 by Nathanael         #+#    #+#             */
/*   Updated: 2022/05/27 16:37:20 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief	Destroys the mutex passed through
 * @param	philo	The philosopher to find and destroy the pthread_mutex
**/
void	delete_mut(t_philo *philo)
{
	int	index;

	index = 0;
	while (index < philo->prog->num_philo)
	{
		pthread_mutex_destroy(&philo->mut[index]);
		index++;
	}
}
