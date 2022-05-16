/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:19:55 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/16 12:39:01 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	overflow_check(int augend, int addend);
static int	va_end_and_return(va_list *ap);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed_cnt;
	int		print_cnt;

	if (format == NULL)
		return (-1);
	printed_cnt = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			print_cnt = ft_parse(&format, &ap);
			if (overflow_check(printed_cnt, print_cnt))
				return (va_end_and_return(&ap));
			printed_cnt += print_cnt;
			continue ;
		}
		ft_putchr_fd(*format, STDOUT_FILENO);
		format++;
		if (overflow_check(printed_cnt, 1))
			return (va_end_and_return(&ap));
		printed_cnt++;
	}
	va_end(ap);
	return (printed_cnt);
}

static bool	overflow_check(int augend, int addend)
{
	if (INT_MAX - augend < addend || addend == -1)
		return (true);
	return (false);
}

static int	va_end_and_return(va_list *ap)
{
	va_end(*ap);
	return (-1);
}
