/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:19:55 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/17 17:54:35 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	overflow_check(int augend, int addend);
static int	va_end_and_return(va_list *ap);
static bool	simple_print(const char **format, va_list *ap, int *printed_cnt);

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
			print_cnt = ft_parse(&format, &ap);
			if (overflow_check(printed_cnt, print_cnt))
				return (va_end_and_return(&ap));
			printed_cnt += print_cnt;
			continue ;
		}
		if (!simple_print(&format, &ap, &printed_cnt))
			return (FAIL);
	}
	va_end(ap);
	return (printed_cnt);
}

static bool	simple_print(const char **format, va_list *ap, int *printed_cnt)
{
	ft_putchr_fd(**format, STDOUT_FILENO);
	(*format)++;
	if (overflow_check(*printed_cnt, 1))
	{
		va_end(*ap);
		return (false);
	}
	(*printed_cnt)++;
	return (true);
}

static bool	overflow_check(int augend, int addend)
{
	if (INT_MAX - augend < addend || addend == FAIL)
		return (true);
	return (false);
}

static int	va_end_and_return(va_list *ap)
{
	va_end(*ap);
	return (FAIL);
}
