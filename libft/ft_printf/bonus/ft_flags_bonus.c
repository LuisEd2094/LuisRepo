/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:15:50 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/07 10:10:35 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"
#include "../include/libft.h"

int	fg_space_plus(const char *s, char *f, char flg)
{
	int	i;
	int	marker;

	i = 0;
	if (flg == 'u')
		return (0);
	marker = 0;
	while (!is_in_set(s[i], f))
	{	
		if (s[i] == '+')
			marker = 1;
		if (s[i] == ' ' && marker != 1)
			marker = 2;
		i++;
	}
	return (marker);
}

int	fg_hash(const char *s, char *f)
{
	int	i;

	i = 0;
	while ((!is_in_set(s[i], f) && s[i] != '#'))
		i++;
	if (s[i] == '#')
		return (1);
	else
		return (0);
}

int	fg_dash(const char *s, char *f)
{
	int	i;

	i = 0;
	while ((!is_in_set(s[i], f) && s[i] != '-'))
		i++;
	if (s[i] == '-')
		return (1);
	else
		return (0);
}

int	fg_number(const char *s, char f)
{
	int		i;

	i = 0;
	while ((s[i] <= '0' || s[i] > '9') && s[i] != f && s[i] != '.')
		i++;
	if (s[i] == f || s[i] == '.')
		return (0);
	else
		return ((int)ft_atoi(&s[i]));
}

int	fg_point(const char *s, char *f)
{
	int	i;

	i = 0;
	while (s[i] != '.' && (!is_in_set(s[i], f)))
		i++;
	if (s[i] == '.')
		return (1);
	else
		return (0);
}
