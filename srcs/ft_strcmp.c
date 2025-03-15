/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:06:01 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/03/15 13:06:02 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *lhs, const char *rhs)
{
	while (*lhs && *rhs
		&& (unsigned char)*lhs++ == (unsigned char)*rhs++)
		continue ;
	if ((unsigned char)*lhs < (unsigned char)*rhs)
		return (-1);
	if ((unsigned char)*lhs > (unsigned char)*rhs)
		return (1);
	return (0);
}
