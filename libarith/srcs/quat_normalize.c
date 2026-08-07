/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:57:13 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/14 22:21:46 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "q_rsqrt.h"
#include "quaternion.h"

// Normalisation of quaternions.
t_quat	quat_normalize(t_quat q)
{
	float	norm;

	norm = q_rsqrtf(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);
	q.w *= norm;
	q.x *= norm;
	q.y *= norm;
	q.z *= norm;
	return (q);
}
