/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:16:15 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 16:21:25 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	size_t	len;
	ssize_t	res;

	len = 1;
	while (0 < len)
	{
		errno = 0;
		res = write(fd, &c, 1);
		if (errno == EINTR && -1 == res)
			continue ;
		return ;
	}
}

// int	main(void)
// {
// 	int		fd = 0;
// 	char	text = 'a';

// 	ft_putchar_fd(text, fd);
// 	return (0);
// }
