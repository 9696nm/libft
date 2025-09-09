/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_axis_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:57:13 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/14 22:21:46 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "quaternion.h"
#include "vecter3.h"

// Quaternions from axes and angles.
t_quat	quat_axis_angle(t_vec3 v, float angle)
{
	float	half_angle;
	float	s;
	t_quat	q;

	half_angle = angle * 0.5f;
	s = sinf(half_angle);
	q.w = cosf(half_angle);
	q.x = v.x * s;
	q.y = v.y * s;
	q.z = v.z * s;
	return (q);
}
