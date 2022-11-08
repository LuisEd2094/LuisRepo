/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:59:52 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/07 11:10:13 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_atoi(const char *nptr)
{
	size_t	nmr;
	int		i;
	size_t	sign;

	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	nmr = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nmr = (nmr * 10) + (nptr[i] - '0');
		i++;
	}
	nmr *= sign;
	return (nmr);
}
