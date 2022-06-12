/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:09:59 by shwatana          #+#    #+#             */
/*   Updated: 2022/06/12 17:10:19 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	simple_print(const char **format, va_list *ap, int *printed_cnt, int fd)
{
	ft_putchr_fd(**format, fd);
	(*format)++;
	if (printf_overflow_check(*printed_cnt, 1))
	{
		va_end(*ap);
		return (false);
	}
	(*printed_cnt)++;
	return (true);
}

bool	printf_overflow_check(int augend, int addend)
{
	if (INT_MAX - augend < addend || addend == FAIL)
		return (true);
	return (false);
}

int	va_end_and_return(va_list *ap)
{
	va_end(*ap);
	return (FAIL);
}
