/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:36:37 by Nathanael         #+#    #+#             */
/*   Updated: 2022/05/27 16:37:03 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief	Checks each parameter and frees as nessesary
 * @param	prog	The structure containing the malloc'd program
 * @param	philo	The structure containing the malloc'd philosopher
 * @param	mut		The structure containing the thread mutex
 * @return	Returns EXIT_SUCCESS
**/
int	ph_free(t_prog *prog, t_philo *philo, pthread_mutex_t *mut)
{
	if (philo != NULL)
		free(philo);
	if (mut != NULL)
		free(mut);
	if (prog != NULL)
		free(prog);
	return (EXIT_SUCCESS);
}
