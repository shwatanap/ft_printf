/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:19:55 by shwatana          #+#    #+#             */
/*   Updated: 2022/06/12 17:08:22 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed_cnt;
	int		print_cnt;

	if (format == NULL)
		return (FAIL);
	printed_cnt = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			print_cnt = ft_parse(&format, &ap, STDOUT_FILENO);
			if (printf_overflow_check(printed_cnt, print_cnt))
				return (va_end_and_return(&ap));
			printed_cnt += print_cnt;
			continue ;
		}
		if (!simple_print(&format, &ap, &printed_cnt, STDOUT_FILENO))
			return (FAIL);
	}
	va_end(ap);
	return (printed_cnt);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		printed_cnt;
	int		print_cnt;

	if (format == NULL)
		return (FAIL);
	printed_cnt = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			print_cnt = ft_parse(&format, &ap, fd);
			if (printf_overflow_check(printed_cnt, print_cnt))
				return (va_end_and_return(&ap));
			printed_cnt += print_cnt;
			continue ;
		}
		if (!simple_print(&format, &ap, &printed_cnt, fd))
			return (FAIL);
	}
	va_end(ap);
	return (printed_cnt);
}

int	ft_vprintf(int fd, const char *format, va_list *ap)
{
	int	printed_cnt;
	int	print_cnt;

	if (format == NULL)
		return (FAIL);
	printed_cnt = 0;
	while (*format)
	{
		if (*format == '%')
		{
			print_cnt = ft_parse(&format, ap, fd);
			if (printf_overflow_check(printed_cnt, print_cnt))
				return (va_end_and_return(ap));
			printed_cnt += print_cnt;
			continue ;
		}
		if (!simple_print(&format, ap, &printed_cnt, fd))
			return (FAIL);
	}
	return (printed_cnt);
}
