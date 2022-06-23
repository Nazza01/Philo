/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:28:54 by Nathanael         #+#    #+#             */
/*   Updated: 2022/05/27 17:31:36 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief	Checks each argument character against 0 to 9 (inclusive) for
 * non numbers in argv
 * @param	The argument list to check
 * @return	EXIT_SUCCESS if the function did not find any non-integer numbers
 * EXIT_FAILURE if the function did find non-integer characters
**/
static int	arg_checker(char **av)
{
	int	in;
	int	dex;

	in = 1;
	dex = 0;
	while (av[in])
	{
		dex = 0;
		while (av[in][dex] != '\0')
		{
			if ((av[in][dex] < '0' || av[in][dex] > '9') && dex != 0)
				return (EXIT_FAILURE);
			dex++;
		}
		in++;
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief	Initializes and assigns the argument list from main to assign using
 * atoi and check the contents if they are actually numbers
 * @param	prog	The program structure
 * @param	av		The main's argument vector
 * @return	If the check fails it will return EXIT_FAILURE, if all the checks
 * pass, then the program will return EXIT_SUCCESS.
**/
int	init_arg(t_prog *prog, char **av)
{
	if (arg_checker(av))
	{
		ft_error("Error did not detect numbers in argument list", EXIT_FAILURE);
		return (EXIT_FAILURE);
	}
	prog->total_eat = 0;
	prog->start_time = t_ms();
	prog->num_philo = ft_atoi(av[1]);
	prog->time_die = ft_atoi(av[2]);
	prog->time_eat = ft_atoi(av[3]);
	prog->time_sleep = ft_atoi(av[4]);
	if (prog->num_philo <= 0 || prog->time_die <= 0 || prog->time_eat <= 0 || \
		prog->time_sleep <= 0)
		return (EXIT_FAILURE);
	if (av[5])
	{
		prog->must_eat = ft_atoi(av[5]);
		if (prog->must_eat <= 0)
			return (EXIT_FAILURE);
	}
	else
		prog->must_eat = -1;
	return (EXIT_SUCCESS);
}
