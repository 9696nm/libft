/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:33:33 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/26 13:42:04 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stddef.h> /* size_t */

/* Original */
int		ft_atoi(const char *str);
void	*ft_calloc(size_t n, size_t size);

long	ft_strtol(const char *nptr, char **endptr, int base);

/* Non-standard */
char	*ft_itoa(int n);
