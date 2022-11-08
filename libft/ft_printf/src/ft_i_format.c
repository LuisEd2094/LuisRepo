/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:50:42 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/03 15:52:42 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

int	i_format(int arg)
{
	char	*itoa;

	if (!arg)
		itoa = ft_strdup("0");
	else
		itoa = ft_itoa(arg);
	if (!itoa)
		return (-1);
	return (put_str(itoa));
}
