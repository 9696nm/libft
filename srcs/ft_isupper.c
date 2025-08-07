/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:58:20 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/02 18:58:21 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}

// #include <ctype.h>
// #include <stdio.h>
// #include <limits.h>
// #include "libft.h"
// int	main(void)
// {
// 	int	c;

// 	c = -2;
// 	while(c < UCHAR_MAX)
// 	{
// 		printf("%d : %c : %d\n", c, c, isupper(c));
// 		if (isupper(c))
// 		{
// 			ft_putbit(c, 4);
// 			ft_putchar_fd('\n', 1);
// 		}
// 		c++;
// 	}
// 	return (0);
// }
