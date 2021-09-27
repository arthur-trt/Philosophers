/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affich.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:34:18 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/27 19:09:59 by atrouill         ###   ########.fr       */
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
	if (state == FORK)
		printf("%ld %zu has taken a fork\n", chrono_rolex(), phil.barcode);
	else if (state == SLEEP)
		printf("%ld %zu is sleeping\n", chrono_rolex(), phil.barcode);
	else if (state == EAT)
		printf("%ld %zu is eating\n", chrono_rolex(), phil.barcode);
	else if (state == THINK)
		printf("%ld %zu is thinking\n", chrono_rolex(), phil.barcode);
	else if (state == DEAD)
	{
		phil.data->end_zion = true;
		printf("%ld %zu has died\n", chrono_rolex(), phil.barcode);
		return ;
	}
	pthread_mutex_unlock(&(phil.data->aff));
}
