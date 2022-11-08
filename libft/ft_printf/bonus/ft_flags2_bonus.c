/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:15:37 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/07 10:50:54 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	fg_zero(const char *s, char *f)
{
	int	i;

	i = 0;
	while (s[i] != '0' && !is_in_set(s[i], f) && !(s[i] >= '1' && s[i] < '9'))
		i++;
	if (s[i] == '0')
		return (1);
	else
		return (0);
}

int	get_presicion(const char *s, char f)
{
	int	i;
	int	presicion;

	presicion = 0;
	i = 0;
	while (s[i] != f && s[i] != '.')
		i++;
	if (s[i] == '.')
		presicion = fg_number(&s[++i], f);
	return (presicion);
}

t_flags	check_flags(const char *s, char *f)
{
	t_flags	new;

	new.type = ck_format(s);
	new.width = fg_number(s, new.type);
	new.marker = fg_space_plus(s, f, new.type);
	new.dash = fg_dash(s, f);
	new.presicion = get_presicion(s, new.type);
	new.point = fg_point(s, f);
	new.zero = fg_zero(s, f);
	new.is_valid = 1;
	if (new.type == 'x' || new.type == 'X')
		new.hash = fg_hash(s, f);
	return (new);
}
