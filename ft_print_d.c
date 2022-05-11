/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:02:02 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/11 21:27:34 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd);

int	ft_print_d(int fd, va_list *ap)
{
	int	num;
	int	print_num;

	num = (int)va_arg(*ap, int);
	print_num = ft_putnbr_fd(num, fd);
	return (print_num);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	print_num;

	print_num = 1;
	if (n == INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	else if (n < 0)
	{
		ft_putchr_fd('-', fd);
		print_num = ft_putnbr_fd((n * -1), fd);
		print_num++;
	}
	else if (n >= 10)
	{
		print_num = ft_putnbr_fd((n / 10), fd);
		ft_putchr_fd(n % 10 + '0', fd);
		print_num++;
	}
	else
		ft_putchr_fd(n + '0', fd);
	return (print_num);
}
