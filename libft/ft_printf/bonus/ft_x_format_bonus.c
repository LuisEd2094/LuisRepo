/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_format_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:34:15 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/07 10:46:51 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"

int	ft_hx_len(unsigned int arg)
{
	int	len;

	len = 0;
	while (arg != 0)
	{
		len++;
		arg /= 16;
	}
	return (len);
}

char	*ft_hex(unsigned int arg, char format)
{
	char	*new;
	int		len;
	char	*base;

	len = ft_hx_len(arg);
	new = ft_calloc((len + 1), sizeof(char));
	if (!new)
		return (NULL);
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	while (arg)
	{
		new[--len] = base[arg % 16];
		arg /= 16;
	}
	return (new);
}

static char	*join_all(char *zeros, char *hex, t_flags flg)
{
	char	*zeros_hex;
	char	*zeros_hex_pre;
	char	*ze_x;

	if (flg.hash && flg.is_valid && flg.type == 'x')
		ze_x = "0x";
	else if (flg.hash && flg.is_valid && flg.type == 'X')
		ze_x = "0X";
	else
		ze_x = "";
	zeros_hex = ft_strjoin(zeros, hex);
	if (!zeros_hex)
		return (NULL);
	zeros_hex_pre = ft_strjoin(ze_x, zeros_hex);
	ft_free_strs(&zeros_hex, 0, 0);
	if (!zeros_hex_pre)
		return (NULL);
	return (zeros_hex_pre);
}

static char	*add_prefix(char *hex, t_flags flg, int hex_len)
{
	char	*new;
	char	*zeros;

	zeros = "";
	if ((flg.presicion > hex_len) || (flg.zero && !(flg.point) \
				&& (flg.width > hex_len)))
	{
		zeros = get_zeros(flg, hex_len);
		if (!zeros)
		{
			ft_free_strs(&hex, 0, 0);
			return (NULL);
		}
	}
	new = join_all(zeros, hex, flg);
	if (zeros[0] == '0')
		ft_free_strs(&zeros, 0, 0);
	ft_free_strs(&hex, 0, 0);
	if (!new)
		return (NULL);
	return (new);
}

int	x_format(const char *s, unsigned int arg)
{
	t_flags	flg;
	char	*hex;

	flg = check_flags(s, "xX");
	if (!arg)
	{
		flg.is_valid = 0;
		hex = get_invalid_hex(flg);
	}
	else
		hex = ft_hex(arg, flg.type);
	if (!hex)
		return (-1);
	if (flg.zero && flg.width && flg.hash && flg.is_valid && !(flg.point))
		flg.width -= 2;
	if (flg.hash || flg.point || flg.zero)
		hex = add_prefix(hex, flg, (int)ft_strlen(hex));
	if (!hex)
		return (-1);
	if (flg.width > (int)ft_strlen(hex))
		hex = add_spaces(hex, flg, (int)ft_strlen(hex));
	if (!hex)
		return (-1);
	return (put_str(hex));
}
