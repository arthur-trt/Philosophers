/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blue_pills.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:19:49 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/28 10:55:35 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_pole_emploi(t_philo *philo)
{
	insta_post(*philo, SLEEP);
	dodo(philo->data->time_sleep);
	insta_post(*philo, THINK);
}

static void	chose_fork(t_philo *p, pthread_mutex_t **f1, pthread_mutex_t **f2)
{
	if (p->barcode % 2 == 0)
	{
		*f1 = &(p->data->fork[p->barcode - 1]);
		*f2 = &(p->data->fork[(p->barcode) % p->data->nbr_philo]);
	}
	else
	{
		*f2 = &(p->data->fork[p->barcode - 1]);
		*f1 = &(p->data->fork[(p->barcode) % p->data->nbr_philo]);
	}
}

void	philo_insta_food_blog(t_philo *philo)
{
	pthread_mutex_t	*f1;
	pthread_mutex_t	*f2;

	chose_fork(philo, &f1, &f2);
	pthread_mutex_lock(f1);
	insta_post(*philo, FORK);
	pthread_mutex_lock(f2);
	insta_post(*philo, FORK);
	pthread_mutex_lock(&(philo->write));
	philo->last_eat = chrono_rolex();
	philo->nbr_eat++;
	pthread_mutex_unlock(&(philo->write));
	insta_post(*philo, EAT);
	dodo(philo->data->time_eat);
	if (philo->nbr_eat == philo->data->nbr_eat)
		philo->full_stomach = true;
	pthread_mutex_unlock(f2);
	pthread_mutex_unlock(f1);
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
