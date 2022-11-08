/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:16:20 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/07 11:05:30 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

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

int	ft_format(const char *source, va_list ap, int i, char format)
{
	if (format == 'c')
		return (c_format(&source[i], va_arg(ap, int)));
	else if (format == 's')
		return (s_format(&source[i], va_arg(ap, char *)));
	else if (format == 'i' || format == 'd')
		return (i_format(&source[i], va_arg(ap, int)));
	else if (format == 'p')
		return (p_format(&source[i], va_arg(ap, unsigned long)));
	else if (format == 'u')
		return (u_format (&source[i], va_arg(ap, unsigned long)));
	else if (format == 'x' || format == 'X')
		return (x_format(&source[i], va_arg(ap, unsigned int)));
	else if (format == '%')
		return (c_format(&source[i], format));
	else
		return (-1);
}

int	count_move_i(int temp, int *i, const char *s)
{
	int	c_count;

	if (s[*i] == '%')
	{
		c_count = temp;
		*i += i_mover(&s[*i]);
	}
	else
	{
		c_count = 1;
		*i += 1;
	}
	return (c_count);
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
			temp = ft_format(s, ap, (i + 1), ck_format(&s[i + 1]));
		else
			temp = put_char(s[i]);
		if (temp == -1)
			return (-1);
		c_count += temp;
		if (temp == 1 && s[i] != '%')
			i++;
		else
			i += i_mover (&s[i]);
	}
	va_end(ap);
	return (c_count);
}
