/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:18:42 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/11 11:59:52 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data **data)
{
	size_t	i;

	(*data)->philo = malloc(sizeof(t_philo) * ((*data)->nbr_philo));
	(*data)->fork = malloc(sizeof(pthread_mutex_t) * ((*data)->nbr_philo));
	if ((*data)->philo == NULL || (*data)->fork == NULL)
		return ;
	(*data)->dead = false;
	i = 0;
	ft_memset((*data)->philo, '\0', sizeof(t_philo) * ((*data)->nbr_philo));
	while (i < (*data)->nbr_philo)
	{
		(*data)->philo[i].barcode = i + 1;
		(*data)->philo[i].data = (*data);
		(*data)->philo[i].last_eat = 0;
		(*data)->philo[i].full_stomach = false;
		pthread_mutex_init(&((*data)->fork[i]), NULL);
		pthread_mutex_init(&((*data)->philo[i].write), NULL);
		i++;
	}
}

void	create_philo(t_data *data)
{
	size_t	i;

	i = 0;
	init_philo(&data);
	pthread_mutex_init(&(data->aff), NULL);
	if (data->nbr_philo == 1)
	{
		pthread_create(&data->philo[i].thread, NULL,
			&philo_hello_darkness, (void *)(&data->philo[i]));
	}
	else
	{
		while (i < data->nbr_philo)
		{
			pthread_create(&data->philo[i].thread, NULL,
				&philo_lifestyle, (void *)(&data->philo[i]));
			i++;
		}
	}
}
