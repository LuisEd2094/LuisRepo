/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:08:41 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/11/07 11:09:52 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_flags
{
	int		width;
	int		marker;
	int		dash;
	int		presicion;
	int		format;
	int		point;
	int		is_valid;
	int		zero;
	int		hash;
	char	type;
}	t_flags;

char	*add_spaces(char *str, t_flags flg, int len);
char	*get_zeros(t_flags flg, int itoa_len);
char	*get_spaces(t_flags flg, int hex_len);
char	*join_spaces(char *hex, char *spaces, t_flags flg);
char	*get_invalid_hex(t_flags flg);
int		ft_p_hex_len(char *hex, t_flags flg);
int		fg_hash(const char *s, char *f);
char	*ft_printf_itoa(int n);
int		ft_printf(const char *s, ...);
int		fg_space_plus(const char *s, char *f, char flg);
int		fg_number(const char *s, char f);
int		fg_dash(const char *s, char *f);
int		fg_point(const char *s, char *f);
int		fg_zero(const char *s, char *f);
int		c_format(const char *s, char arg);
int		s_format(const char *s, char *arg);
int		x_format(const char *s, unsigned int arg);
int		i_format(const char *s, int arg);
int		p_format(const char *s, unsigned long arg);
int		u_format(const char *s, unsigned int arg);

int		ft_free_strs(char **str, char **str2, char **str3);
int		put_char(char c);
int		put_str(char *s);
int		c_left_space(t_flags flg, char arg);
int		c_right_space(t_flags flg, char arg);
int		space(char *str, t_flags flg, int len, int (*f)(t_flags, char *, int));
int		is_in_set(char c, char const *set);
int		i_mover(const char *source);
int		filter_flag(const char *s, char *f);
int		write_symb_space(int marker);
int		get_presicion(const char *s, char f);
char	*ft_hex_creator(unsigned long arg);
int		ft_hex_len(unsigned long arg);
int		ft_num_len(unsigned int num);
char	*ft_uitoa(unsigned int n);
t_flags	check_flags(const char *s, char *f);
char	ck_format(const char *source);

#endif
