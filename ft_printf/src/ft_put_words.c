/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:08:53 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/03 15:48:30 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
