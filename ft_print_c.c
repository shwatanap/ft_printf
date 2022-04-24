/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 09:40:00 by shwatana          #+#    #+#             */
/*   Updated: 2022/04/24 11:13:27 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(int fd, va_list *ap)
{
	char	c;

	c = (char)va_arg(*ap, int);
	return (write(fd, &c, sizeof(char)));
}
