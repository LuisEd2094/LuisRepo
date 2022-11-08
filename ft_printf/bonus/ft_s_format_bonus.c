/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_format_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:17:17 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/07 10:40:05 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"

int	s_space(char	*arg, t_flags flg, int len)
{
	char	*spaces;
	char	*new;

	spaces = get_spaces(flg, len);
	if (!spaces)
		return (ft_free_strs(&arg, 0, 0));
	if (flg.dash)
		new = ft_strjoin(arg, spaces);
	else
		new = ft_strjoin(spaces, arg);
	ft_free_strs(&spaces, &arg, 0);
	if (!new)
		return (-1);
	else
		return (put_str(new));
}

char	*get_arg(char *arg, t_flags flg, int len)
{
	char	*new;
	int		size;

	if (len > flg.presicion && flg.point)
	{
		new = ft_calloc(flg.presicion + 1, sizeof(char));
		size = flg.presicion + 1;
	}
	else
	{
		new = ft_calloc(len + 1, sizeof(char));
		size = len + 1;
	}
	if (!new)
		return (NULL);
	else
		ft_strlcpy(new, arg, size);
	return (new);
}

int	s_format(const char *s, char *arg)
{
	t_flags	flags;
	char	*new_arg;

	flags = check_flags(s, "s");
	if (flags.point == 1 && (flags.presicion == 0) && !(flags.width > 0))
		return (0);
	if (!arg)
		new_arg = get_arg("(null)", flags, (int)ft_strlen("(null)"));
	else
		new_arg = get_arg(arg, flags, (int)ft_strlen(arg));
	if (!new_arg)
		return (-1);
	if (flags.width > (int)ft_strlen(new_arg))
		return (s_space(new_arg, flags, (int)ft_strlen(new_arg)));
	else
		return (put_str(new_arg));
}
