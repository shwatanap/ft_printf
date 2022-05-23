/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:12:17 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/23 11:19:27 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(int fd, va_list *ap)
{
	ssize_t	len;
	char	*str;

	str = (char *)va_arg(*ap, char *);
	if (str == NULL)
	{
		len = ft_putstr_fd_with_len("(null)", fd);
		return ((int)len);
	}
	len = ft_putstr_fd_with_len(str, fd);
	if (len < 0 || INT_MAX < len)
		return (FAIL);
	return ((int)len);
}
