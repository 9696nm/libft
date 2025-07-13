/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:26:12 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 16:22:44 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "ft/string.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			size;
	unsigned char	*result;

	size = 0;
	if (s == NULL)
		return (NULL);
	if (len && start < (unsigned int)ft_strlen((char *)s) + 1)
	{
		while (s[start + size] && size < len)
			size++;
	}
	result = (unsigned char *)malloc(sizeof(unsigned char) * (size + 1));
	if (result == NULL)
		return (NULL);
	result[size] = '\0';
	while (size-- > 0)
		result[size] = ((unsigned char *)s)[start + size];
	return ((char *)result);
}
