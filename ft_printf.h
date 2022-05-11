/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:16:19 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/12 00:57:24 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
// # include "libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>
// debug
# include <stdio.h>

# define FAIL -1
# define SPECIFIER "cspdiuxX%"
# define SMALL_HEX "0123456789abcdef"
# define LARGE_HEX "0123456789ABCDEF"

typedef enum e_specifier
{
	NO = -1,
	C,
	S,
	P,
	D,
	I,
	U,
	SX,
	LX,
	PER
}		t_specifier;

// ft_printf.c
int		ft_printf(const char *format, ...) __attribute__((format(printf, 1,
					2)));

// ft_parse.c
int		ft_parse(const char **format, va_list *ap);

// ft_print_c.c
int		ft_print_c(int fd, va_list *ap);

// ft_print_per.c
int		ft_print_per(int fd);

// ft_print_d.c
int		ft_print_d(int fd, va_list *ap);

// ft_print_s.c
int		ft_print_s(int fd, va_list *ap);

// ft_print_p.c
int		ft_print_p(int fd, va_list *ap);

// ft_print_u.c
int		ft_print_u(int fd, va_list *ap);

// ft_print_x.c
int		ft_putnbr_hex(int fd, va_list *ap, t_specifier specifier);

// ft_printf_utils.c
ssize_t	ft_strchr_idx(char *str, char c);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *str, int fd);
void	ft_putchr_fd(char c, int fd);

#endif
