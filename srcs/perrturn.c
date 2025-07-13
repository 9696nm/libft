/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perrturn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:31:37 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/08 18:44:53 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	perrturn(int status, char *msg)
{
	if (status)
		perror(msg);
	return (status);
}
// dprintf?
