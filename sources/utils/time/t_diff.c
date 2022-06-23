/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_diff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:25:51 by Nathanael         #+#    #+#             */
/*   Updated: 2022/05/30 14:39:17 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief	Uses philo passed through to subtract the current time by the 
 * programs' start time
 * @param	philo	The philisopher's struct
 * @return	Returns the unix timestamp difference
**/
unsigned long	t_diff(t_philo *philo)
{
	return (t_ms() - philo->prog->start_time);
}
