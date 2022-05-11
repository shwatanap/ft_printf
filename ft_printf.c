/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:19:55 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/11 19:19:52 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed_cnt;

	printed_cnt = 0;
	va_start(ap, format);
	if (format == NULL)
		printed_cnt = -1;
	while (*format)
	{
		if (*format == '%')
			printed_cnt += ft_parse(&format, &ap);
		else
		{
			write(STDOUT_FILENO, format, 1);
			format++;
			printed_cnt++;
		}
	}
	va_end(ap);
	return (printed_cnt);
}
