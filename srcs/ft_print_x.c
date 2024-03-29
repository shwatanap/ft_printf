/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:06:16 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/12 17:41:28 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_hex(int fd, unsigned int n, t_specifier specifier);
static int	ft_putnbr_hex_rec(int fd, unsigned int n, t_specifier specifier);

int	ft_print_x(int fd, va_list *ap, t_specifier specifier)
{
	int				print_cnt;
	unsigned int	n;

	n = (unsigned int)va_arg(*ap, unsigned int);
	print_cnt = ft_putnbr_hex_rec(fd, n, specifier);
	return (print_cnt);
}

static int	ft_putnbr_hex_rec(int fd, unsigned int n, t_specifier specifier)
{
	int	print_cnt;

	if (n < 16)
	{
		ft_put_hex(fd, n, specifier);
		return (1);
	}
	print_cnt = ft_putnbr_hex_rec(fd, n / 16, specifier);
	ft_putnbr_hex_rec(fd, n % 16, specifier);
	return (print_cnt + 1);
}

static void	ft_put_hex(int fd, unsigned int n, t_specifier specifier)
{
	char	c;

	if (specifier == SX)
		c = SMALL_HEX[n];
	else if (specifier == LX)
		c = LARGE_HEX[n];
	else
		return ;
	ft_putchr_fd(c, fd);
}
