/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_from_to.c                                     :+:      :+:    :+:   */
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

// Quaternions from two direction vectors.
t_quat	quat_from_to(t_vec3 from, t_vec3 to)
{
	float	dot;
	t_vec3	axis;

	dot = vec3_dot(from, to);
	if ((1.0f - EPSILON) < dot)
		return ((t_quat){0.0f, 0.0f, 0.0f, 1.0f});
	if (dot < (-1.0f + EPSILON))
	{
		if (fabsf(from.x) < EPSILON && fabsf(from.y) < EPSILON)
			axis = (t_vec3){1.0f, 0.0f, 0.0f};
		else
			axis = (t_vec3){-from.y, from.x, 0.0f};
		axis = vec3_normalize(axis);
		return (quat_axis_angle(axis, M_PI));
	}
	axis = vec3_normalize(vec3_cross(from, to));
	return (quat_axis_angle(axis, acosf(dot)));
}
