/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:06:47 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/03 15:52:49 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_hex_len(unsigned long arg)
{
	int	len;

	len = 0;
	while (arg != 0)
	{
		len++;
		arg /= 16;
	}
	return (len);
}

char	*ft_hex_creator(unsigned long arg)
{
	char	*new;
	int		i;
	int		hex_len;
	char	*hex;

	if ((long)arg == LONG_MIN)
		return (ft_strdup ("0x8000000000000000"));
	else if (arg == ULONG_MAX)
		return (ft_strdup("0xffffffffffffffff"));
	hex_len = ft_hex_len(arg);
	new = ft_calloc((hex_len + 3), sizeof(char));
	if (!new)
		return (NULL);
	hex = "0123456789abcdef";
	i = hex_len + 1;
	while (arg)
	{
		new[i--] = hex[arg % 16];
		arg /= 16;
	}
	new[i--] = 'x';
	new[i] = '0';
	return (new);
}

int	p_format(unsigned long arg)
{
	char	*hex;

	if (!arg)
		hex = ft_strdup("0x0");
	else
		hex = ft_hex_creator(arg);
	if (!hex)
		return (-1);
	return (put_str(hex));
}
