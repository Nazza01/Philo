/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:30:23 by Nathanael         #+#    #+#             */
/*   Updated: 2022/05/14 12:32:08 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief	Allows for a smooth exit to your program
 * @param	msg		The message to output
 * @param	code	The code to exit by
 * @return	Exits using system exit function
**/
void	ft_error(char *msg, int code)
{
	printf("%s", msg);
	exit(code);
}
