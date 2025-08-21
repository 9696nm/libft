/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:32:15 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/21 21:46:37 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft/stdio.h"

void	print_bits(const void *ptr, size_t byte)
{
	int				bit_size;
	unsigned char	*num;

	bit_size = 8;
	num = (unsigned char *)ptr;
	if (byte--)
	{
		while (bit_size--)
			ft_putchar_fd((num[byte] >> bit_size & 0b1) + '0', STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
		print_bits(ptr, byte);
	}
	else
		ft_putchar_fd('\n', STDOUT_FILENO);
}

void	ft_putbit(unsigned long int num, uint8_t bytesize)
{
	bytesize *= 8;
	while (bytesize--)
		ft_putchar_fd((num >> bytesize & 0b1) + '0', STDOUT_FILENO);
}
