/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:58:10 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/02 18:58:11 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_islower(int c)
{
	return ('a' <= c && c <= 'z');
}

// #include <ctype.h>
// #include <stdio.h>
// #include <limits.h>
// #include "libft.h"

// int	main(void)
// {
// 	char	c;

// 	c = 0;
// 	while(c < CHAR_MAX)
// 	{
// 		printf("%c : %d\n", c, islower(c));
// 		if (islower(c))
// 		{
// 			ft_putbit(c, 1);
// 			ft_putchar_fd('\n', 0);
// 		}
// 		c++;
// 	}
// 	return (0);
// }
