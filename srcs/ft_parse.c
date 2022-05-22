/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:23:29 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/22 12:39:21 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(va_list *ap, t_specifier specifier, int fd);

int	ft_parse(const char **format, va_list *ap, int fd)
{
	t_specifier	specifier;
	int			printed_cnt;

	(*format)++;
	specifier = (t_specifier)ft_strchr_idx(SPECIFIER, **format);
	if (specifier == NO)
	{
		ft_putchr_fd(**format, fd);
		printed_cnt = 1;
	}
	else
		printed_cnt = ft_convert(ap, specifier, fd);
	(*format)++;
	return (printed_cnt);
}

int	ft_convert(va_list *ap, t_specifier specifier, int fd)
{
	if (specifier == C)
		return (ft_print_c(fd, ap));
	else if (specifier == S)
		return (ft_print_s(fd, ap));
	else if (specifier == P)
		return (ft_print_p(fd, ap));
	else if (specifier == D || specifier == I)
		return (ft_print_d(fd, ap));
	else if (specifier == U)
		return (ft_print_u(fd, ap));
	else if (specifier == SX)
		return (ft_print_x(fd, ap, specifier));
	else if (specifier == LX)
		return (ft_print_x(fd, ap, specifier));
	else if (specifier == PER)
		return (ft_print_per(fd));
	return (FAIL);
}
