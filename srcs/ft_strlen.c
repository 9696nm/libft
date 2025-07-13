/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:56:40 by hmori             #+#    #+#             */
/*   Updated: 2025/02/22 13:16:21 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	int		n;
// 	int		m;
// 	char	text[] = "Hello World";

// 	n = strlen(text);
// 	m = ft_strlen(text);
// 	printf("ord (%d), ft (%d)\n", n, m);
// 	return (0);
// }
