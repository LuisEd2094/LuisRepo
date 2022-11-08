/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:54:15 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/07 10:27:38 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	ck_format(const char *source)
{
	char	*set;
	int		i;
	int		j;

	i = 0;
	j = 0;
	set = "csipduxX%";
	while (!is_in_set(source[j], set))
		j++;
	i = 0;
	while (set[i])
	{
		if (source[j] == set[i])
			return (set[i]);
		i++;
	}
	return (0);
}

int	ft_format(va_list ap, char format)
{
	if (format == 'c')
		return (put_char(va_arg(ap, int)));
	else if (format == 's')
		return (s_format(va_arg(ap, char *)));
	else if (format == 'i' || format == 'd')
		return (i_format(va_arg(ap, int)));
	else if (format == 'p')
		return (p_format(va_arg(ap, unsigned long)));
	else if (format == 'u')
		return (u_format (va_arg(ap, unsigned long)));
	else if (format == 'x' || format == 'X')
		return (x_format(va_arg(ap, unsigned int), format));
	else if (format == '%')
		return (put_char('%'));
	else
		return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		c_count;
	int		temp;

	i = 0;
	c_count = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
			temp = ft_format(ap, ck_format(&s[++i]));
		else
			temp = put_char(s[i]);
		if (temp < 0)
			return (-1);
		c_count += temp;
		i++;
	}
	va_end(ap);
	return (c_count);
}
