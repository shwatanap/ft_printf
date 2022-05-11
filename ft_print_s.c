/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:12:17 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/11 21:32:05 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(int fd, va_list *ap)
{
	size_t	len;
	char	*str;

	str = (char *)va_arg(*ap, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	len = ft_strlen(str);
	ft_putstr_fd(str, fd);
	return ((int)len);
}
