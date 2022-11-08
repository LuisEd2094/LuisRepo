/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:10:13 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/09/26 18:59:56 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*found;

	found = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			found = (&((char *)s)[i]);
		i++;
	}
	if (c == '\0')
		found = (&((char *)s)[i]);
	return (found);
}
