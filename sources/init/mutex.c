/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:43:17 by Nathanael         #+#    #+#             */
/*   Updated: 2022/05/28 12:07:20 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief	Initializes the thread mutex for use with locking and unlocking the
 * states
 * @param	prog	The program variables
 * @param	philo	The philosophers' struct
 * @return	EXIT_FAILURE if the program does not pass or initailize the checks
**/
int	init_mutex(t_prog *prog, t_philo *philo)
{
	int				index;
	pthread_mutex_t	print;
	pthread_mutex_t	*mut;

	index = 0;
	mut = malloc(sizeof(pthread_mutex_t) * prog->num_philo);
	if (!mut || !philo)
		return (ph_free(prog, philo, mut));
	while (index < prog->num_philo)
	{
		if (pthread_mutex_init(&mut[index++], 0) != EXIT_SUCCESS)
			return (ph_free(prog, philo, mut));
	}
	if (pthread_mutex_init(&print, 0))
		return (ph_free(prog, philo, mut));
	init_philo(prog, philo, mut, &print);
	return (EXIT_SUCCESS);
}
