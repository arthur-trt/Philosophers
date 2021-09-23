/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:18:42 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/23 15:26:10 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo(t_data *data)
{
	pthread_t	test;
	size_t	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_create(&test, NULL, &philo_lifestyle, &i);
		i++;
	}
}
