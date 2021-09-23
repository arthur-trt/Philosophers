/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:45:35 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/23 14:55:57 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_data
{
	size_t		nbr_philo;
	time_t		time_die;
	time_t		time_eat;
	time_t		time_sleep;
	size_t		nbr_eat;
}				t_data;

/*
** DEBUG.C
*/
void	print_data(t_data data);

/*
** UTILS.C
*/
bool	ft_isdigit(char *s);
void	*ft_memset(void *b, int c, size_t len);

/*
** STR_UTILS.C
*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char *s);
void	ft_putstr_error(char *s);
size_t	ft_atoi(const char *str);

#endif
