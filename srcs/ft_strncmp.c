/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:47:02 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 16:22:30 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 - c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	size_t	any_cmp = 1000000;
// 	char	*s1 = "a3", *s2 = "a3";

// 	printf("len : %zu\ns1  : %s\ns2  : %s\n", any_cmp, s1, s2);
// 	printf("org : %i\n", strncmp(s1, s2, any_cmp));
// 	fflush(stdout);
// 	printf("ft_ : %i\n", ft_strncmp(s1, s2, any_cmp));
// 	return (0);
// }
