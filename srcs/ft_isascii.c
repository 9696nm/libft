/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:07:22 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 16:19:39 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int num)
{
	return (0 <= num && num <= 127);
}

// #include <stdio.h>
// #include <ctype.h>
// #include <limits.h>

// int	main(void)
// {
// 	for (int i = 0; i < UCHAR_MAX + 1; i++)
// 	{
// 		if (ft_isascii(i))
// 			printf("%c (%d)\n", i, i);
// 	}
// 	return (0);
// }
