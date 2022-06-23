/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:17:29 by Nathanael         #+#    #+#             */
/*   Updated: 2022/05/30 14:50:43 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int c, char **av)
{
	int				index;
	t_prog			*prog;
	t_philo			*philo;
	pthread_t		*thread;

	index = 0;
	if (c < 5 || c > 6)
		ft_error("Error incorrect amount of args\n", EXIT_FAILURE);
	prog = malloc(sizeof(t_prog));
	if (init_arg(prog, av))
		return (ph_free(prog, 0, 0));
	philo = malloc(sizeof(t_philo) * prog->num_philo);
	if (init_mutex(prog, philo) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	thread = malloc(sizeof(pthread_t) * prog->num_philo);
	while (index < philo->prog->num_philo)
	{
		pthread_create(&thread[index], NULL, ph_start, philo + index);
		usleep(100);
		index++;
	}
	check_died(prog, philo);
	free(thread);
	return (0);
}
