/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:47:22 by hmori             #+#    #+#             */
/*   Updated: 2025/02/23 00:29:25 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft/stdio.h"
#include "ft/string.h"

void	ft_putstr_fd(char *str, int fd)
{
	if (str)
		write(fd, str, ft_strlen(str));
}

// void	ft_putstr_fd(char *str, int fd)
// {
// 	size_t	len;

// 	if (str == NULL)
// 		return ;
// 	len = ft_strlen(str);
// 	while (INT_MAX < len)
// 	{
// 		write(fd, str, INT_MAX);
// 		str += INT_MAX;
// 		len -= INT_MAX;
// 	}
// 	write(fd, str, len);
// }

// #include <stdlib.h>
// #include <limits.h>

// int	main(void)
// {
// 	int		fd = 0;
// 	char	*text = "abcd012";

// 	ft_putstr_fd(text, fd);
// 	return (0);
// }
