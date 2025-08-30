/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:57:13 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/14 22:21:46 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

// Normalisation of quaternions
t_quat	quat_normalize(t_quat q)
{
	float	norm;

	norm = q_rsqrtf(q.w * q.w + q.v.x * q.v.x + q.v.y * q.v.y + q.v.z * q.v.z);
	q.w *= norm;
	q.v.x *= norm;
	q.v.y *= norm;
	q.v.z *= norm;
	return (q);
}

// Product of quaternions
t_quat	quat_multiply(t_quat q1, t_quat q2)
{
	t_quat	result;
	t_vec3		v1;
	t_vec3		v2;

	v1 = q1.v;
	v2 = q2.v;
	result.w = q1.w * q2.w - v1.x * v2.x - v1.y * v2.y - v1.z * v2.z;
	result.v.x = q1.w * v2.x + v1.x * q2.w + v1.y * v2.z - v1.z * v2.y;
	result.v.y = q1.w * v2.y - v1.x * v2.z + v1.y * q2.w + v1.z * v2.x;
	result.v.z = q1.w * v2.z + v1.x * v2.y - v1.y * v2.x + v1.z * q2.w;
	return (result);
}

// Set up conjugate quaternions.
t_quat	quat_conjugate(const t_quat q)
{
	t_quat	q_conj;

	q_conj.w = q.w;
	q_conj.v.x = -q.v.x;
	q_conj.v.y = -q.v.y;
	q_conj.v.z = -q.v.z;
	return (q_conj);
}

// Rotation of 3D vectors by quaternions
t_quat	quat_rotate(t_quat qv, t_quat p)
{
	t_quat	q_conj;
	t_quat	result;

	q_conj = quat_conjugate(qv);
	result = quat_multiply(quat_multiply(qv, p), q_conj);
	return (result);
}

// Quaternions from axes and angles.
t_quat	quat_axis_angle(float x, float y, float z, float angle)
{
	float		half_angle;
	float		s;
	t_quat	q;

	half_angle = angle * 0.5f;
	s = sinf(half_angle);
	q.w = cosf(half_angle);
	q.v.x = x * s;
	q.v.y = y * s;
	q.v.z = z * s;
	return (q);
}
