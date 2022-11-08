/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:15:53 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/09/26 18:56:37 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len || s[0] == '\0')
		len = 0;
	else if (((start + len) == s_len + 1) || len > ft_strlen(s))
		len = s_len - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	if (len > 0)
		ft_strlcpy(sub, (char *)(s + start), len + 1);
	else
		sub[0] = '\0';
	return (sub);
}
