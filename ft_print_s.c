/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:12:17 by shwatana          #+#    #+#             */
/*   Updated: 2022/04/24 11:14:58 by shwatana         ###   ########.fr       */
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
		write(fd, "(null)", sizeof(char) * 6);
		return (6);
	}
	len = ft_strlen(str);
	write(fd, str, (int)len);
	return ((int)len);
}
