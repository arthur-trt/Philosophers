/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:30:54 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/23 14:50:37 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#ifdef DEBUG
void	print_data(t_data data)
{
	printf("Number of philosophers : %zu\n", data.nbr_philo);
	printf("Time to die : %ld\n", data.time_die);
	printf("Time to eat : %ld\n", data.time_eat);
	printf("Time to sleep : %ld\n", data.time_sleep);
	printf("Number of eat : %zu\n\n", data.nbr_eat);
}
#else

void	print_data(t_data data)
{
	(void)data;
}
#endif
