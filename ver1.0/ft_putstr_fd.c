/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmori <hmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:47:22 by hmori             #+#    #+#             */
/*   Updated: 2023/10/22 17:21:47 by hmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	while (ft_strlen(s) > INT_MAX)
		write(fd, s, ft_strlen(s + INT_MAX));
	write(fd, s, ft_strlen(s));
}

// #include <stdlib.h>
// #include <limits.h>

// int	main(void)
// {
// 	int		fd = 0;
// 	char	*text = "abcd012";

// 	ft_putstr_fd(text, fd);
// 	return (0);
// }
