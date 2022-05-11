/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:23:29 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/11 21:15:02 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(va_list *ap, t_specifier specifier);

int	ft_parse(const char **format, va_list *ap)
{
	t_specifier	specifier;
	int			printed_cnt;

	(*format)++;
	specifier = (t_specifier)ft_strchr_idx(SPECIFIER, **format);
	if (specifier == NO)
	{
		write(STDOUT_FILENO, *format, sizeof(char));
		printed_cnt = 1;
	}
	else
		printed_cnt = ft_convert(ap, specifier);
	(*format)++;
	return (printed_cnt);
}

int	ft_convert(va_list *ap, t_specifier specifier)
{
	int	printed_cnt;

	printed_cnt = 0;
	if (specifier == C)
		printed_cnt += ft_print_c(STDOUT_FILENO, ap);
	else if (specifier == S)
		printed_cnt += ft_print_s(STDOUT_FILENO, ap);
	else if (specifier == P)
		printed_cnt += ft_print_p(STDOUT_FILENO, ap);
	else if (specifier == D || specifier == I)
		printed_cnt += ft_print_d(STDOUT_FILENO, ap);
	else if (specifier == U)
		printed_cnt += ft_print_u(STDOUT_FILENO, ap);
	else if (specifier == SX)
		printed_cnt += ft_putnbr_hex(STDOUT_FILENO, ap, specifier);
	else if (specifier == LX)
		printed_cnt += ft_putnbr_hex(STDOUT_FILENO, ap, specifier);
	else if (specifier == PER)
		printed_cnt += ft_print_per(STDOUT_FILENO);
	return (printed_cnt);
}
