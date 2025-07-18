/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:31:51 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 16:19:22 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "ft/string.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t	mal_size;
	char	*result;

	if (n == 0 || size == 0)
		mal_size = 1;
	else
	{
		if (n > SIZE_MAX / size)
			return (NULL);
		mal_size = n * size;
	}
	result = (void *)malloc(mal_size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, mal_size);
	return ((void *)result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*test1;
// 	char	*test2;

// 	test1 = (char *)calloc(SIZE_MAX, SIZE_MAX);
// 	test2 = (char *)ft_calloc(SIZE_MAX / 4, 4);
// 	printf ("%p\n", test1);
// 	printf ("%p\n", test2);
// 	free (test1);
// 	free (test2);
// 	return (0);
// }
