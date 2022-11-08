/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_format_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:08:24 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/07 10:41:58 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf_bonus.h"

static char	*add_prefix(char *uitoa, t_flags flg, int uitoa_len)
{
	char	*new;
	char	*zeros;

	zeros = "";
	if ((flg.presicion > uitoa_len) || (flg.zero && !(flg.point) \
				&& (flg.width > uitoa_len)))
	{
		zeros = get_zeros(flg, uitoa_len);
		if (!zeros)
		{
			ft_free_strs(&uitoa, 0, 0);
			return (NULL);
		}
	}	
	new = ft_strjoin(zeros, uitoa);
	if (zeros[0] == '0')
		ft_free_strs(&zeros, 0, 0);
	ft_free_strs(&uitoa, 0, 0);
	if (!new)
		return (NULL);
	return (new);
}

int	u_format(const char *s,	unsigned int arg)
{
	char	*uitoa;
	t_flags	flg;

	flg = check_flags(s, "u");
	if (!arg && flg.presicion < 1 && flg.point)
		uitoa = ft_strdup("");
	else if (!arg)
		uitoa = ft_strdup("0");
	else
		uitoa = ft_uitoa(arg);
	if (!uitoa)
		return (-1);
	if (flg.point || (flg.zero))
		uitoa = add_prefix(uitoa, flg, (int)ft_strlen(uitoa));
	if (!uitoa)
		return (-1);
	if (flg.width > (int)ft_strlen(uitoa))
		uitoa = add_spaces(uitoa, flg, (int)ft_strlen(uitoa));
	if (!uitoa)
		return (-1);
	return (put_str(uitoa));
}
