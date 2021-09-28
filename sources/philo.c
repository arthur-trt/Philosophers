/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:46:23 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/28 10:09:37 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_args(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		ft_putstr_error("Wrong number of arguments\n");
		return (false);
	}
	i = 0;
	while (i < argc - 1)
	{
		if (ft_isdigit(argv[i + 1]) == false)
		{
			ft_putstr_error("Wrong arguments\n");
			return (false);
		}
		i++;
	}
	return (true);
}

static void	init_args(t_data **data, int argc, char **argv)
{
	(*data)->nbr_philo = ft_atoi(argv[1]);
	(*data)->time_die = ft_atoi(argv[2]);
	(*data)->time_eat = ft_atoi(argv[3]);
	(*data)->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*data)->nbr_eat = ft_atoi(argv[5]);
	else
		(*data)->nbr_eat = -1;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_args(argc, argv) == false)
		return (EXIT_FAILURE);
	data = malloc(sizeof(t_data));
	ft_memset(data, '\0', sizeof(t_data));
	init_args(&data, argc, argv);
	print_data(*data);
	create_philo(data);
	god(data);
	return (EXIT_SUCCESS);
}
