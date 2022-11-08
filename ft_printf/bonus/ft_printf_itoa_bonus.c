/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:16:33 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/10/31 18:06:46 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_int_len(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_printf_itoa(int n)
{
	char	*new;
	int		i;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("2147483648"));
	if (n < 0)
		n *= -1;
	len = ft_int_len(n);
	new = ft_calloc((len + 1), sizeof(char));
	if (!new)
		return (0);
	i = len - 1;
	while (n)
	{
		new[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (new);
}
