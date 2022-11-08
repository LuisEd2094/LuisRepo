/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:55:18 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/03 15:55:32 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	s_format(char *arg)
{
	char	*new_arg;

	if (!arg)
		new_arg = ft_strdup("(null)");
	else
		new_arg = ft_strdup(arg);
	if (!new_arg)
		return (-1);
	return (put_str(new_arg));
}
