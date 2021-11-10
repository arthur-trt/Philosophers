/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:45:35 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/10 10:18:01 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

typedef enum e_state	t_state;
typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

struct s_philo
{
	size_t			barcode;
	ssize_t			nbr_eat;
	time_t			last_eat;
	bool			full_stomach;
	t_data			*data;
	pthread_t		thread;
	pthread_mutex_t	write;
};

struct s_data
{
	size_t			nbr_philo;
	time_t			time_die;
	time_t			time_eat;
	time_t			time_sleep;
	ssize_t			nbr_eat;
	bool			dead;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	aff;
};

enum e_state {
	FORK,
	SLEEP,
	EAT,
	THINK,
	DEAD,
	EAT_END,
};

/*
** BLUE_PILLS.C
*/

void	philo_pole_emploi(t_philo *philo);
void	philo_insta_food_blog(t_philo *philo);
void	*philo_hello_darkness(void *philo);
void	*philo_lifestyle(void *barcode);

/*
** THREADS.C
*/

void	create_philo(t_data *data);
void	*god(t_data *data);
void	*mr_smith_die(t_data *data);

/*
** DEBUG.C
*/

void	print_data(t_data data);

/*
** TIME.C
*/

time_t	get_time(void);
void	dodo(time_t sleep);
time_t	chrono_rolex(void);

/*
** AFFICH.C
*/

void	insta_post(t_philo phil, t_state state);

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
