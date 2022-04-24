/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:23:29 by shwatana          #+#    #+#             */
/*   Updated: 2022/04/24 11:14:15 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(const char **start, const char **format, va_list *ap,
		t_specifier specifier);

int	ft_parse(const char **start, const char **format, va_list *ap)
{
	t_specifier	specifier;
	int			printed_cnt;

	(void)ap;
	(void)start;
	(*format)++;
	specifier = (t_specifier)ft_strchr_idx(SPECIFIER, **format);
	printed_cnt = ft_convert(start, format, ap, specifier);
	return (printed_cnt);
}

int	ft_convert(const char **start, const char **format, va_list *ap,
		t_specifier specifier)
{
	int	printed_cnt;
	int	fd;

	(void)start;
	fd = STDOUT_FILENO;
	printed_cnt = 0;
	if (specifier == C)
		printed_cnt += ft_print_c(fd, ap);
	else if (specifier == S)
		printed_cnt += ft_print_s(fd, ap);
	else if (specifier == P)
		printf("p");
	else if (specifier == D)
		printf("d");
	else if (specifier == I)
		printf("i");
	else if (specifier == U)
		printf("u");
	else if (specifier == SX)
		printf("sx");
	else if (specifier == LX)
		printf("lx");
	else if (specifier == PER)
		printf("per");
	else
		printf("else");
	(*format)++;
	return (printed_cnt);
}
