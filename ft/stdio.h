/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdio.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:33:33 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/26 13:41:58 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

/* Non-standard */
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

/* Extra */
void	ft_putbit(unsigned long int num, uint8_t bytesize);
int		perrturn(int status, char *msg);
int		ret_errmsg(int code, const char *msg);
