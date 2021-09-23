/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:14:57 by atrouill          #+#    #+#             */
/*   Updated: 2021/09/23 14:54:03 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_isdigit(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

/*
**	Fills the first n bytes of the memory area pointed to by b with the
**	constant byte c.
**
**	@param b Area to fill
**	@param c Byte used for fill
**	@param len Number of byte to write
**
**	@return Pointer to the memory area s
*/
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;

	ptr = b;
	while (len-- > 0)
		*ptr++ = c;
	return (b);
}
