/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_words_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:17:04 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/07 10:56:12 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	put_char(char c)
{
	if (write (1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	put_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (put_char(s[i]) == -1)
			return (ft_free_strs(&s, 0, 0));
		i++;
	}
	ft_free_strs(&s, 0, 0);
	return (i);
}
