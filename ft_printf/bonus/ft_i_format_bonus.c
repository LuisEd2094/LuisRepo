/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_format_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:34:39 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/07 10:33:31 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf_bonus.h"

char	*get_zeros(t_flags flg, int len)
{
	char	*new;
	int		i;

	i = 0;
	new = NULL;
	if (flg.point)
	{
		new = ft_calloc((flg.presicion - len + 1), sizeof(char));
		if (!new)
			return (NULL);
		while (i < (flg.presicion - len))
			new[i++] = '0';
	}
	else if (flg.zero)
	{
		if (flg.marker)
			len++;
		new = ft_calloc(((flg.width - len) + 1), sizeof(char));
		if (!new)
			return (NULL);
		while (i < (flg.width - len))
			new[i++] = '0';
	}
	return (new);
}	

static char	*join_all(char *zeros, char *itoa, t_flags flg)
{
	char	*zeros_itoa;
	char	*zeros_itoa_symbols;
	char	*symbols_or_space;

	if (flg.marker == 1)
		symbols_or_space = "+";
	else if (flg.marker == 2)
		symbols_or_space = " ";
	else if (flg.marker == 3)
		symbols_or_space = "-";
	else
		symbols_or_space = "";
	zeros_itoa = ft_strjoin(zeros, itoa);
	if (!zeros_itoa)
		return (NULL);
	zeros_itoa_symbols = ft_strjoin(symbols_or_space, zeros_itoa);
	ft_free_strs(&zeros_itoa, 0, 0);
	if (!zeros_itoa_symbols)
		return (NULL);
	return (zeros_itoa_symbols);
}

int	check_help(t_flags f, int len, int mrk)
{
	if (((f.presicion > len) || (f.zero && !(f.point) \
				&& (f.width > len))) && mrk == 1)
		return (1);
	else if (((f.width - len) == 1 && f.marker \
				&& f.zero && !f.presicion) && mrk == 2)
		return (1);
	else
		return (0);
}

static char	*add_prefix(char *itoa, t_flags flg, int itoa_len)
{
	char	*new;
	char	*zeros;

	zeros = "";
	if (check_help(flg, itoa_len, 1))
	{	
		if (check_help(flg, itoa_len, 2))
			zeros = "";
		else
		{
			zeros = get_zeros(flg, itoa_len);
			if (!zeros)
			{
				ft_free_strs(&itoa, 0, 0);
				return (NULL);
			}
		}
	}		
	new = join_all(zeros, itoa, flg);
	if (zeros[0] == '0')
		ft_free_strs(&zeros, 0, 0);
	ft_free_strs(&itoa, 0, 0);
	if (!new)
		return (NULL);
	return (new);
}

int	i_format(const char *s, int arg)
{
	char	*itoa;
	t_flags	flg;

	flg = check_flags(s, "id");
	if (!arg && flg.presicion < 1 && flg.point)
		itoa = ft_strdup("");
	else if (!arg)
		itoa = ft_strdup("0");
	else
		itoa = ft_printf_itoa(arg);
	if (!itoa)
		return (-1);
	if (arg < 0)
		flg.marker = 3;
	if (flg.presicion || (flg.zero || flg.marker))
		itoa = add_prefix(itoa, flg, (int)ft_strlen(itoa));
	if (!itoa)
		return (-1);
	if (flg.width > (int)ft_strlen(itoa))
		itoa = add_spaces(itoa, flg, (int)ft_strlen(itoa));
	if (!itoa)
		return (-1);
	return (put_str(itoa));
}
