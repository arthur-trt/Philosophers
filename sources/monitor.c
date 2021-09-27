/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:22:56 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/27 19:40:37 by atrouill         ###   ########.fr       */
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
		if (data->philo[i].nbr_eat >= data->nbr_eat)
		{
			pthread_detach(data->philo[i].thread);
		}
		i++;
		if (i == data->nbr_philo)
			i = 0;
	}
	return (NULL);
}
