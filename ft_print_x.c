/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:06:16 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/11 15:07:37 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_hex(int fd, int n, t_specifier specifier);
static int	ft_putnbr_hex_rec(int fd, unsigned int n, t_specifier specifier);

int	ft_putnbr_hex(int fd, va_list *ap, t_specifier specifier)
{
	int					print_cnt;
	unsigned long long	n;

	n = (unsigned long long)va_arg(*ap, void *);
	print_cnt = ft_putnbr_hex_rec(fd, n, specifier);
	return (print_cnt);
}

static int	ft_putnbr_hex_rec(int fd, unsigned int n, t_specifier specifier)
{
	int	print_cnt;

	print_cnt = 1;
	if (n < 16)
		ft_put_hex(fd, n, specifier);
	else
	{
		print_cnt = ft_putnbr_hex_rec(fd, n / 16, specifier);
		ft_putnbr_hex_rec(fd, n % 16, specifier);
		print_cnt++;
	}
	return (print_cnt);
}

static void	ft_put_hex(int fd, int n, t_specifier specifier)
{
	char	c;

	if (specifier == SX)
		c = SMALL_HEX[n];
	else if (specifier == LX)
		c = LARGE_HEX[n];
	else
		return ;
	write(fd, &c, sizeof(char));
}
