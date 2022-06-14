/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shwatana <shwatana@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 10:49:39 by shwatana          #+#    #+#             */
/*   Updated: 2022/06/14 15:02:38 by shwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

ssize_t	ft_strchr_idx(const char *str, int c)
{
	char	chrc;
	size_t	i;
	size_t	len;

	len = ft_strlen(str) + 1;
	i = 0;
	chrc = (char)c;
	while (i < len)
	{
		if (str[i] == chrc)
			return ((ssize_t)i);
		i++;
	}
	return (FAIL);
}

ssize_t	ft_putstr_fd_with_len(char *str, int fd)
{
	size_t	len;
	size_t	result;

	if (str == NULL)
		return (FAIL);
	len = ft_strlen(str);
	result = len;
	while (INT_MAX < len)
	{
		write(fd, str, INT_MAX);
		str += INT_MAX;
		len -= INT_MAX;
	}
	write(fd, str, len);
	return (result);
}

void	ft_putchr_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}
