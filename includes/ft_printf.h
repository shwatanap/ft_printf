/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:16:19 by shwatana          #+#    #+#             */
/*   Updated: 2022/08/03 21:46:56 by shwatana         ###   ########.fr       */
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
int		ft_printf(const char *format, ...)
		__attribute__((format(printf, 1, 2)));
int		ft_dprintf(int fd, const char *format, ...)
		__attribute__((format(printf, 2, 3)));
int		ft_vprintf(int fd, const char *format, va_list *ap);

// ft_parse.c
int		ft_parse(const char **format, va_list *ap, int fd);

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
int		ft_print_x(int fd, va_list *ap, t_specifier specifier);

// ft_printf_utils.c
ssize_t	ft_strchr_idx(const char *str, int c);
ssize_t	ft_putstr_fd_with_len(char *str, int fd);
void	ft_putchr_fd(char c, int fd);

// ft_printf_sub.c
bool	simple_print(const char **format, va_list *ap, int *printed_cnt,
			int fd);
bool	printf_overflow_check(int augend, int addend);
int		va_end_and_return(va_list *ap);

#endif
