/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 10:55:21 by cledant           #+#    #+#             */
/*   Updated: 2017/02/22 12:11:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define LONG_MIN (-__LONG_MAX__ -1L)
# define LLONG_MIN (-__LONG_LONG_MAX__-1LL)

typedef struct	s_flags
{
	int			space;
	int			sharp;
	int			pad_zero;
	int			pad_space;
	size_t		pad_size;
	int			sign;
	int			precision;
	size_t		preci_size;
	int			double_pc;
	int			length;
	size_t		type;
	char		other_char;
}				t_flags;

char			*ft_printf_analyse_string(char *format);
size_t			ft_printf_parse_type(char *format, va_list list_arg,
					int *skip, size_t *nb_print);
void			ft_printf_init_data(t_flags *data);
void			ft_printf_setup_data(char *data, t_flags *flag);
int				ft_printf_print_args(t_flags *flag, va_list list_arg);
int				ft_printf_is_converter(char *format);
int				ft_printf_is_modifier(char *format);
int				ft_printf_is_flag(char *format);
void			ft_printf_fill_flag(char *format, t_flags *data);
void			ft_printf_fill_converter(char *format, t_flags *data);
void			ft_printf_fill_modifier(char *format, t_flags *data);
int				ft_printf_s(va_list list_arg, t_flags *flag);
int				ft_printf_c(va_list list_arg, t_flags *flag);
int				ft_printf_d(va_list list_arg, t_flags *flag);
int				ft_printf_u(va_list list_arg, t_flags *flag);
int				ft_printf_p(va_list list_arg, t_flags *flag);
int				ft_printf_o(va_list list_arg, t_flags *flag);
int				ft_printf_other(t_flags *flag);
int				ft_printf_xx(va_list list_arg, int maj, t_flags *flag);
int				ft_printf_ls(va_list list_arg, t_flags *flag);
int				ft_printf_lc(va_list list_arg, t_flags *flag);
int				ft_printf_ld(va_list list_arg, t_flags *flag);
int				ft_printf_lo(va_list list_arg, t_flags *flag);
int				ft_printf_lu(va_list list_arg, t_flags *flag);
int				ft_printf_lxx(va_list list_arg, int maj, t_flags *flag);
int				ft_printf_lld(va_list list_arg, t_flags *flag);
int				ft_printf_llo(va_list list_arg, t_flags *flag);
int				ft_printf_llu(va_list list_arg, t_flags *flag);
int				ft_printf_llxx(va_list list_arg, int maj, t_flags *flag);
int				ft_printf_hd(va_list list_arg, t_flags *flag);
int				ft_printf_ho(va_list list_arg, t_flags *flag);
int				ft_printf_hu(va_list list_arg, t_flags *flag);
int				ft_printf_hxx(va_list list_arg, int maj, t_flags *flag);
int				ft_printf_hhd(va_list list_arg, t_flags *flag);
int				ft_printf_hho(va_list list_arg, t_flags *flag);
int				ft_printf_hhu(va_list list_arg, t_flags *flag);
int				ft_printf_hhxx(va_list list_arg, int maj, t_flags *flag);
char			*ft_printf_octal_converter(unsigned int n);
char			*ft_printf_hex_converter(unsigned int n);
char			*ft_printf_octal_converter_long_int(unsigned long int n);
char			*ft_printf_hex_converter_long_int(unsigned long int n);
char			*ft_printf_octal_converter_long_long_int(unsigned \
					long long int n);
char			*ft_printf_hex_converter_long_long_int(unsigned \
					long long int n);
char			*ft_printf_itoa_short_int(short int n);
char			*ft_printf_itoa_unsigned_short_int(short int n);
char			*ft_printf_itoa_unsigned(unsigned int n);
char			*ft_printf_itoa_long_int(long int n);
char			*ft_printf_itoa_unsigned_long_int(unsigned long int n);
char			*ft_printf_itoa_long_long_int(long long int n);
char			*ft_printf_itoa_unsigned_long_long_int(unsigned long int n);
char			*ft_printf_chain_modifier(char *s, long long int val,
					t_flags *f);
wchar_t			*ft_printf_chain_modifier_w(wchar_t *s, long long int val,
					t_flags *f);
char			*ft_printf_chain_modifier_ull(char *s,
					unsigned long long int val, t_flags *f);
char			*ft_printf_add_front_string(char *s, char *s2);
char			*ft_printf_add_n_behind_string(char *s, size_t p_len, char c);
wchar_t			*ft_printf_add_n_behind_w_string(wchar_t *s, size_t p_len,
					char c);
char			*ft_printf_mod_precision(char *s, size_t pre_len);
char			*ft_printf_mod_size(char *s, size_t size_len);
char			*ft_printf_mod_rm_preci(char *s);
char			*ft_printf_mod_precision_str_simple(char *s, size_t pre_size);
wchar_t			*ft_printf_mod_precision_str_w(wchar_t *s, size_t pre_size);
char			*ft_printf_mod_size(char *s, size_t pre_size);
char			*ft_printf_mod_size_zero(char *s, size_t pre_size);
char			*ft_printf_mod_size_zero_string(char *s, size_t pre_size);
char			*ft_printf_mod_size_zero_hex(char *s, size_t pre_size);
wchar_t			*ft_printf_mod_size_w(wchar_t *s, size_t pre_size);
wchar_t			*ft_printf_mod_size_zero_w(wchar_t *s, size_t pre_size);
int				ft_printf_length_minus_2(t_flags *flags, va_list list_args);
int				ft_printf_length_minus_1(t_flags *flags, va_list list_args);
int				ft_printf_length_0(t_flags *flags, va_list list_args);
int				ft_printf_length_1(t_flags *flags, va_list list_args);
int				ft_printf_length_j(t_flags *flags, va_list list_args);
int				ft_printf_length_z(t_flags *flags, va_list list_args);
int				ft_printf_length_2(t_flags *flags, va_list list_args);
void			ft_printf_set_flag_zero_sc(t_flags *f);
void			ft_printf_init_analyse(int *flag_flag, size_t *len,
					char **cpy_format, char *format);
char			*ft_str_front_n_remove(char *s, size_t len);
wchar_t			*ft_wlen_strcpy(wchar_t *dst, wchar_t *src, size_t wlen);
size_t			ft_wlen_strnlen(wchar_t *s, size_t wlen);

#endif
