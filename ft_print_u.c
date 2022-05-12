/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:14:12 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/12 01:33:52 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(int fd, unsigned int n);

int	ft_print_u(int fd, va_list *ap)
{
	int				print_cnt;
	unsigned int	n;

	n = (unsigned int)va_arg(*ap, unsigned int);
	print_cnt = ft_putnbr_u(fd, n);
	return (print_cnt);
}

int	ft_putnbr_u(int fd, unsigned int n)
{
	int	print_cnt;

	print_cnt = 1;
	if (n < 10)
		ft_putchr_fd(n + '0', fd);
	else
	{
		print_cnt = ft_putnbr_u(fd, n / 10);
		ft_putnbr_u(fd, n % 10);
		print_cnt++;
	}
	return (print_cnt);
}
