/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_format_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:16:03 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/07 10:35:12 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"

int	ft_hex_len(unsigned long arg)
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

char	*ft_hex_creator(unsigned long arg)
{
	char	*new;
	int		i;
	int		hex_len;
	char	*hex;

	if ((long)arg == LONG_MIN)
		return (ft_strdup ("0x8000000000000000"));
	else if (arg == ULONG_MAX)
		return (ft_strdup("0xffffffffffffffff"));
	hex_len = ft_hex_len(arg) + 2;
	new = ft_calloc((hex_len + 1), sizeof(char));
	if (!new)
		return (NULL);
	hex = "0123456789abcdef";
	i = hex_len - 1;
	while (arg)
	{
		new[i--] = hex[arg % 16];
		arg /= 16;
	}
	new[i--] = 'x';
	new[i] = '0';
	return (new);
}

char	*join_spaces(char *hex, char *spaces, t_flags flg)
{
	char	*new;

	if (flg.dash)
		new = ft_strjoin(hex, spaces);
	else
		new = ft_strjoin(spaces, hex);
	ft_free_strs(&hex, &spaces, 0);
	if (!new)
		return (NULL);
	return (new);
}

int	p_format(const char *s, unsigned long arg)
{
	t_flags	flg;
	char	*hex;
	char	*spaces;

	hex = NULL;
	spaces = NULL;
	flg = check_flags(s, "p");
	if (arg == 0)
		hex = ft_strdup("0x0");
	else if (!arg)
		hex = ft_strdup("(nil)");
	else
		hex = ft_hex_creator(arg);
	if (!hex)
		return (-1);
	if (flg.width > (int)ft_strlen(hex))
	{
		spaces = get_spaces(flg, (int)ft_strlen(hex));
		if (!spaces)
			return (ft_free_strs(&hex, 0, 0));
		hex = join_spaces(hex, spaces, flg);
		if (!hex)
			return (-1);
	}	
	return (put_str(hex));
}
