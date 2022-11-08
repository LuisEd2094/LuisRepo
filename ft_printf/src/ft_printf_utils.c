/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:54:39 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/03 15:55:20 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	i_mover(const char *source)
{
	int		i;
	char	*set;

	i = 1;
	set = "csipduxX%";
	while (!is_in_set(source[i], set))
		i++;
	if (is_in_set(source[i], set))
		i++;
	return (i);
}
