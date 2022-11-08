/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:55:50 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/03 15:56:11 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

int	u_format(unsigned int arg)
{
	char	*uitoa;

	if (!arg)
		uitoa = ft_strdup("0");
	else
		uitoa = ft_uitoa(arg);
	if (!uitoa)
		return (-1);
	return (put_str(uitoa));
}
