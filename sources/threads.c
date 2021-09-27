/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:18:42 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/27 19:29:51 by atrouill         ###   ########.fr       */
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
	i = 0;
	ft_memset((*data)->philo, '\0', sizeof(t_philo) * ((*data)->nbr_philo));
	while (i < (*data)->nbr_philo)
	{
		(*data)->philo[i].barcode = i + 1;
		(*data)->philo[i].data = (*data);
		(*data)->philo[i].last_eat = 0;
		pthread_mutex_init(&((*data)->fork[i]), NULL);
		i++;
	}
}

void	create_philo(t_data *data)
{
	size_t	i;

	i = 0;
	init_philo(&data);
	chrono_rolex();
	pthread_mutex_init(&(data->aff), NULL);
	while (i < data->nbr_philo)
	{
		pthread_create(&data->philo[i].thread, NULL,
			&philo_lifestyle, (void *)(&data->philo[i]));
		i++;
	}
}
