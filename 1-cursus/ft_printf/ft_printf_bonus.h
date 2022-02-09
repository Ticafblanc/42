/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:51:54 by mdoquocb          #+#    #+#             */
/*   Updated: 2022/02/09 14:35:49 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

struct	s_flgs
{
	int	minus;
	int	zero;
	int	dot;
	int	precision;
	int	width;
	int	htag;
	int	plus;
	int	space;
};

int		ft_putchar_wid_min(char c, int width);
int		ft_putchar_wid_zero(char c, int width);
int		ft_putchar_wid(char c, int width);
int		ft_putchar(char c);

int		ft_strlen(char *s);
int		ft_putstr_wid_pre(char *s, struct s_flgs flags, int pre_si, int wid_si);
int		ft_putstr_wid(char *s, struct s_flgs flags);
int		ft_putstr_pre(char *s, int prec);
int		ft_putstr(char *s);

int		ft_memlen(unsigned long n);
int		ft_putmem_prewid(unsigned long n, struct s_flgs flags);
int		ft_putmem_wid(unsigned long n, struct s_flgs flags);
int		ft_putmem_pre(unsigned long n, struct s_flgs flags);
int		ft_putmem(unsigned long n, int start);

int		ft_nbrlen(long n);
int		ft_putnbr_prewid(long n, struct s_flgs flags);
int		ft_putnbr_pre(long n, struct s_flgs flags);
int		ft_putnbr_wid(long n, struct s_flgs flags);
int		ft_putnbr(long n);

int		ft_hexlen(unsigned int n);
int		ft_puthex_prewid(unsigned int n, struct s_flgs flags, int cap);
int		ft_puthex_pre(unsigned int n, struct s_flgs flags, int cap);
int		ft_puthex_wid(unsigned int n, struct s_flgs flags, int cap);
int		ft_puthex(unsigned int n, int cap);

int		ft_print_char(char c, struct s_flgs flags);
int		ft_print_str(char *s, struct s_flgs flags);
int		ft_print_mem(unsigned long n, struct s_flgs flags);
int		ft_print_nbr(long n, struct s_flgs flags);
int		ft_print_hex(unsigned int n, struct s_flgs flags, char c);
int		ft_print_htag(int cas);
void	ft_printf_flag_app(int ft, int *flag);
void	ft_printf_flag_app_2(int ft, int *flag, long n);
int		ft_print_other(char c, struct s_flgs flags);

int		ft_is_conversion_specifiers(const char c);
int		is_valid_flag(const char c);
int		ft_atoi_star(const char *s, int *i, va_list args);
void	ft_neg_star(struct s_flgs *flags);
void	flag(const char *s, int *i, struct s_flgs *flags, va_list args);
void	flag2(const char *s, int *i, struct s_flgs *flags, va_list args);

int		ft_dispatch(const char *str, int *i, va_list args);
int		ft_printf(const char *str, ...);
#endif
