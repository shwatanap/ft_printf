/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 10:49:39 by shwatana          #+#    #+#             */
/*   Updated: 2022/05/11 21:21:18 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_strchr_idx(char *str, char c)
{
	ssize_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (FAIL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *str, int fd)
{
	size_t	len;

	if (str == NULL)
		return ;
	len = ft_strlen(str);
	while (INT_MAX < len)
	{
		write(fd, str, INT_MAX);
		str += INT_MAX;
		len -= INT_MAX;
	}
	write(fd, str, len);
}

void	ft_putchr_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}
