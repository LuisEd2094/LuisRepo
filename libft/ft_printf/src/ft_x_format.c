/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:56:14 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/07 11:25:19 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_hx_len(unsigned int arg)
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

char	*ft_hex(unsigned int arg, char format)
{
	char	*new;
	int		len;
	char	*base;

	len = ft_hx_len(arg);
	new = ft_calloc((len + 2), sizeof(char));
	if (!new)
		return (NULL);
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	while (arg)
	{
		new[--len] = base[arg % 16];
		arg /= 16;
	}
	return (new);
}

int	x_format(unsigned int arg, char format)
{
	char	*hex;

	if (!arg)
		hex = ft_strdup("0");
	else
		hex = ft_hex(arg, format);
	if (!hex)
		return (-1);
	return (put_str(hex));
}
