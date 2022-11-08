/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:16:52 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/07 11:07:27 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"

char	*add_spaces(char *str, t_flags flg, int len)
{
	char	*new;
	char	*spaces;
	int		i;

	spaces = ft_calloc((flg.width - len + 1), sizeof(char));
	if (!spaces)
	{
		ft_free_strs(&str, 0, 0);
		return (NULL);
	}
	i = 0;
	while (i < (flg.width - len))
		spaces[i++] = ' ';
	if (flg.dash)
		new = ft_strjoin(str, spaces);
	else
		new = ft_strjoin(spaces, str);
	ft_free_strs(&spaces, &str, 0);
	if (!new)
		return (NULL);
	return (new);
}

char	*get_spaces(t_flags flg, int len)
{
	char	*new;
	int		i;

	new = ft_calloc((flg.width - len + 1), sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (i < (flg.width - len))
			new[i++] = ' ';
	return (new);
}

int	is_in_set(char c, char const *set)
{
	int	i;

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

char	*get_invalid_hex(t_flags flg)
{
	char	*new;

	if (flg.presicion < 1 && flg.point)
		new = ft_strdup("");
	else
		new = ft_strdup("0");
	if (!new)
		return (NULL);
	return (new);
}
