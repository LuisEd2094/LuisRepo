/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_format_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:15:24 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/07 10:11:17 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	c_left_space(t_flags flg, char arg)
{
	int		c_printed;
	int		i;

	i = 1;
	c_printed = 0;
	while (i++ < flg.width)
	{
		if (put_char(' ') != 1)
			return (-1);
		c_printed++;
	}		
	if (put_char(arg) != 1)
		return (-1);
	c_printed++;
	return (c_printed);
}

int	c_right_space(t_flags flg, char arg)
{
	int		c_printed;
	int		i;

	i = 1;
	c_printed = 0;
	if (put_char(arg) != 1)
		return (-1);
	c_printed++;
	while (i++ < flg.width)
	{
		if (put_char(' ') != 1)
			return (-1);
		c_printed++;
	}		
	return (c_printed);
}

int	c_format(const char *s, char arg)
{
	t_flags	flags;

	flags = check_flags(s, "c%");
	if (flags.dash)
		return (c_right_space(flags, arg));
	else if (flags.width > 0)
		return (c_left_space(flags, arg));
	else
		return (put_char(arg));
}
