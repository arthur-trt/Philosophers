/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:22:56 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/27 22:21:05 by atrouill         ###   ########.fr       */
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
		pthread_mutex_lock(&(data->philo[i].write));
		if (data->philo[i].nbr_eat < data->nbr_eat)
		{
			pthread_mutex_unlock(&(data->philo[i].write));
			return (false);
		}
		pthread_mutex_unlock(&(data->philo[i].write));
		i++;
	}
	return (true);
}

void	*god(t_data *data)
{
	time_t	last_eat;
	size_t	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_mutex_lock(&(data->philo[i].write));
		last_eat = data->philo[i].last_eat;
		pthread_mutex_unlock(&(data->philo[i].write));
		if (chrono_rolex() - (last_eat) > data->time_die)
		{
			insta_post(data->philo[i], DEAD);
			return (white_rabbit_matix(data));
		}
		if (++i == data->nbr_philo)
		{
			i = 0;
			if (data->nbr_eat != -1 && all_full(data))
			{
				insta_post(data->philo[i], EAT_END);
				return (white_rabbit_matix(data));
			}
		}
	}
	return (NULL);
}
