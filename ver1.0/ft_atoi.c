/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmori <hmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:54:44 by hmori             #+#    #+#             */
/*   Updated: 2023/10/28 15:53:10 by hmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	space_1check(int i)
{
	return (('\t' <= i && i <= '\r') || i == ' ');
}

int	ft_atoi(const char *str)
{
	long int	result[2];
	long int	inspect;

	while (space_1check(*str))
		str++;
	result[0] = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			result[0] *= -1;
		str++;
	}
	result[1] = 0;
	inspect = 0;
	while ('0' <= *str && *str <= '9')
	{
		result[1] = result[1] * 10 + (*str - '0');
		if (inspect > 0 && result[1] * result[0] < inspect)
			return ((int)LONG_MAX);
		if (inspect < 0 && result[1] * result[0] > inspect)
			return ((int)LONG_MIN);
		str++;
		inspect = result[1] * result[0];
	}
	return ((int)(result[1] * result[0]));
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	*str = "\t-2147483649";

// 	printf ("bef : %s\naft : %d\n", str, ft_atoi(str));
// 	return (0);
// }
