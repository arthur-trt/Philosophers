/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blue_pills.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:19:49 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/27 22:42:14 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_pole_emploi(t_philo *philo)
{
	insta_post(*philo, SLEEP);
	dodo(philo->data->time_sleep);
	insta_post(*philo, THINK);
}

void	philo_insta_food_blog(t_philo *philo)
{
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;

	if (philo->barcode % 2 == 0)
	{
		left = &(philo->data->fork[philo->barcode - 1]);
		right = &(philo->data->fork[(philo->barcode) % philo->data->nbr_philo]);
	}
	else
	{
		right = &(philo->data->fork[philo->barcode - 1]);
		left = &(philo->data->fork[(philo->barcode) % philo->data->nbr_philo]);
	}
	pthread_mutex_lock(left);
	insta_post(*philo, FORK);
	pthread_mutex_lock(right);
	insta_post(*philo, FORK);
	pthread_mutex_lock(&(philo->write));
	philo->last_eat = chrono_rolex();
	philo->nbr_eat++;
	pthread_mutex_unlock(&(philo->write));
	insta_post(*philo, EAT);
	dodo(philo->data->time_eat);
	if (philo->nbr_eat == philo->data->nbr_eat)
		philo->full_stomach = true;
	pthread_mutex_unlock(right);
	pthread_mutex_unlock(left);
}

void	*philo_lifestyle(void *philo)
{
	t_philo	*lfi;

	lfi = (t_philo *)philo;
	if (lfi->barcode % 2 == 0)
		dodo(lfi->data->time_die / 10);
	while (1)
	{
		if (lfi->full_stomach == false)
		{
			philo_insta_food_blog(lfi);
			philo_pole_emploi(lfi);
		}
	}
	return (NULL);
}
