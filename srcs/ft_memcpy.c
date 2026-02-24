/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:07:54 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 16:20:48 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*buf1;
	const unsigned char	*buf2;

	if (n == 0)
		return (dest);
	buf1 = (unsigned char *)dest;
	buf2 = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		buf1[i] = buf2[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	s1[13] = "hello world!";
// 	char	s2[3] = "42";

// /*
// 	for (int i = 0; i < 13; i++)
// 		printf("%2i (%#4x) : %c\n", i, s1[i], s1[i]);
// 	for (int i = 0; i < 3; i++)
// 		printf("%2i (%#4x) : %c\n", i, s2[i], s2[i]);
// */
// /*
// 	printf("s1 : %p\n", s1);
// 	printf("s2 : %p\n", s2);

// 	printf("ret: %p\n", memcpy(NULL, NULL, 0));	// (nil)
// 	printf("ret: %p\n", memcpy(s1, NULL, 0));	// s1 address
// 	printf("ret: %p\n", memcpy(NULL, s2, 0));	// (nil)
// 	printf("ret: %p\n", memcpy(s1, s2, 0));		// s1 address

// 	printf("ret: %p\n", memcpy(NULL, NULL, 1));	// segmentation fault
// 	printf("ret: %p\n", memcpy(s1, NULL, 1));	// segmentation fault
// 	printf("ret: %p\n", memcpy(NULL, s2, 1));	// segmentation fault
// 	printf("ret: %p\n", memcpy(s1, s2, 1));		// s1 address
// */
// /* 
// 	memcpy(s1, NULL, 0);
// 	for (int i = 0; i < 13; i++)
// 		printf("%2i (%#4x) : %c\n", i, s1[i], s1[i]);
// */
// /* 
// 	memcpy(s1, s2, 0);
// 	for (int i = 0; i < 13; i++)
// 		printf("%2i (%#4x) : %c\n", i, s1[i], s1[i]);
// 	return (0);
// */
// /*
// 	memcpy(s1, s2, 10);
// 	for (int i = 0; i < 13; i++)
// 		printf("%2i (%#4x) : %c\n", i, s1[i], s1[i]);
// 	return (0);
// */
// }

