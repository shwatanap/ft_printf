/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:06:16 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/11 21:30:50 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_hex_ull(int fd, unsigned long long n, t_specifier specifier);
static int	ft_putnbr_hex_rec_ull(int fd, unsigned long long n,
				t_specifier specifier);

int	ft_print_p(int fd, va_list *ap)
{
	int					print_cnt;
	unsigned long long	n;

	print_cnt = 2;
	ft_putstr_fd("0x", fd);
	n = (unsigned long long)va_arg(*ap, void *);
	print_cnt += ft_putnbr_hex_rec_ull(fd, n, SX);
	return (print_cnt);
}

static int	ft_putnbr_hex_rec_ull(int fd, unsigned long long n,
		t_specifier specifier)
{
	int	print_cnt;

	print_cnt = 1;
	if (n < 16)
		ft_put_hex_ull(fd, n, specifier);
	else
	{
		print_cnt = ft_putnbr_hex_rec_ull(fd, n / 16, specifier);
		ft_putnbr_hex_rec_ull(fd, n % 16, specifier);
		print_cnt++;
	}
	return (print_cnt);
}

static void	ft_put_hex_ull(int fd, unsigned long long n, t_specifier specifier)
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
