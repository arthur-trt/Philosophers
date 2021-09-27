/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:22:56 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/27 19:49:29 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*white_rabbit_matix(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_detach(data->philo[i++].thread);
	}
	return (NULL);
}

static bool	all_full(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (data->philo[i].nbr_eat < data->nbr_eat)
			return (false);
		i++;
	}
	return (true);

}

void	*god(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (chrono_rolex() - data->philo[i].last_eat > data->time_die)
		{
			insta_post(data->philo[i], DEAD);
			return (white_rabbit_matix(data));
		}
		i++;
		if (i == data->nbr_philo)
			i = 0;
		if (all_full(data))
		{
			insta_post(data->philo[i], EAT_END);
			return (white_rabbit_matix(data));
		}
	}
	return (NULL);
}
