/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:16:19 by shwatana          #+#    #+#             */
/*   Updated: 2022/04/24 10:09:23 by shwatana         ###   ########.fr       */
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
int		ft_printf(const char *format, ...);

// ft_parse.c
int		ft_parse(const char **start, const char **format, va_list *ap);

// ft_print_c.c
int		ft_print_c(int fd, char c);

// ft_printf_utils.c
ssize_t	ft_strchr_idx(char *str, char c);

#endif
