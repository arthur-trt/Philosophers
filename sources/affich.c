/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affich.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:34:18 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/28 11:41:55 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Print the current status of a philosophers depending of his state
**
**	@param barcode Philosopher id
**	@param state State of the philosopher to print
*/
void	insta_post(t_philo phil, t_state state)
{
	pthread_mutex_lock(&(phil.data->aff));
	if (phil.data->dead == false && state == FORK)
		printf("%ld %zu has taken a fork\n", chrono_rolex(), phil.barcode);
	else if (phil.data->dead == false && state == SLEEP)
		printf("%ld %zu is sleeping\n", chrono_rolex(), phil.barcode);
	else if (phil.data->dead == false && state == EAT)
		printf("%ld %zu is eating\n", chrono_rolex(), phil.barcode);
	else if (phil.data->dead == false && state == THINK)
		printf("%ld %zu is thinking\n", chrono_rolex(), phil.barcode);
	else if (phil.data->dead == false && state == DEAD)
	{
		phil.data->dead = true;
		printf("%ld %zu has died\n", chrono_rolex(), phil.barcode);
	}
	else if (phil.data->dead == false && state == EAT_END)
	{
		phil.data->dead = true;
		printf("All philos eaten %zd times\n", phil.data->nbr_eat);
	}
	pthread_mutex_unlock(&(phil.data->aff));
}
