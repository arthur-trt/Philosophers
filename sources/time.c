/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:35:13 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/28 08:46:28 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Obtain current system time in milisecond
**
** @return Current time in ms
*/
time_t	get_time(void)
{
	struct timeval	tv;
	time_t			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

/*
**	Sleep during given time
**
**	@param sleep Time to sleep in milisecond
*/
void	dodo(time_t sleep)
{
	time_t	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < sleep)
		usleep(3);
}

time_t	chrono_rolex()
{
	static time_t	start_time = 0;

	if (start_time == 0)
	{
		start_time = get_time();
		return (0);
	}
	return (get_time() - start_time);
}
