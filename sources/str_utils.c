/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:48:21 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/23 14:56:22 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], STDOUT_FILENO);
		i++;
	}
}

void	ft_putstr_error(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], STDERR_FILENO);
		i++;
	}
}

static char	*ft_clean_str(const char *str)
{
	int		i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	return ((char *)(str + i));
}

/*
**	Convert a string to an int respresentation
**
**	@param str String to convert
**
**	@return int representation of the string
*/
size_t	ft_atoi(const char *str)
{
	int		i;
	size_t	res;
	char	*clean_str;

	i = 0;
	res = 0;
	clean_str = ft_clean_str(str);
	if (clean_str[0] == '+')
		i++;
	while (clean_str[i] >= 48 && clean_str[i] <= 57)
	{
		res = (res * 10) + (clean_str[i] - 48);
		i++;
	}
	return (res);
}
