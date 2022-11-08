/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 09:47:53 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/09/26 18:47:11 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_len_magnitude(int n, int *len, int *magnitude)
{
	*len = 1;
	if (n < 0)
		*len = 2;
	if (n >= 0)
		n = -n;
	*magnitude = 1;
	while (n / *magnitude < -9)
	{
		*magnitude *= 10;
		*len += 1;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	int		magnitude;
	int		i;
	char	*new;

	ft_len_magnitude(n, &len, &magnitude);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	if (n < 0)
		new [i++] = '-';
	if (n > 0)
		n = -n;
	while (magnitude >= 1)
	{
		new[i++] = -((n / magnitude) % 10) + 48;
		magnitude /= 10;
	}
	new[i] = '\0';
	return (new);
}
