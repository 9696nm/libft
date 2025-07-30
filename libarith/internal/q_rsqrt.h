/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_rsqrt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:26:34 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/14 22:01:58 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Q_RSQRT_H
# define Q_RSQRT_H

typedef union u_cast
{
	long int	li;
	float		f;
}	t_cast;

float	q_rsqrtf(float number);

#endif /* Q_RSQRT_H */
