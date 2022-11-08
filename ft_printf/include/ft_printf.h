/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:34:24 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/07 11:08:34 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

char	*ft_printf_itoa(int n);
int		s_format(char *arg);
int		x_format(unsigned int arg, char format);
int		i_format(int arg);
int		p_format(unsigned long arg);
int		u_format(unsigned int arg);
int		ft_printf(const char *s, ...);
int		ft_free_strs(char **str, char **str2, char **str3);
int		put_char(char c);
int		put_str(char *s);
int		is_in_set(char c, char const *set);
int		i_mover(const char *source);

char	*ft_uitoa(unsigned int n);

#endif
