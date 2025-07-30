/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_errmsg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:40:37 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/26 13:40:38 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft/stdio.h"

int	ret_errmsg(int code, const char *msg)
{
	ft_putstr_fd((char *)msg, STDERR_FILENO);
	return (code);
}

// ft_fdの引数constにしろ!!!
