/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libarith.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:41:31 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/26 13:41:35 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBARITH_H
# define LIBARITH_H

typedef struct s_coordinates3
{
	float	x;
	float	y;
	float	z;
}	t_coord3;

typedef struct s_vecter3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_quaternion
{
	float	w;
	t_vec3	v;
}	t_quat;

/* q_rsqrt.c */
float		q_rsqrtf(float number);

/* quaternion.c */
t_quat	quat_normalize(t_quat q);
t_quat	quat_multiply(t_quat q1, t_quat q2);
t_quat	quat_conjugate(const t_quat q);
t_quat	quat_rotate(t_quat qv, t_quat q);
t_quat	quat_axis_angle(float x, float y, float z, float angle);

/* vecter.c */
t_vec3		vecter3_normalize(t_vec3 v);

#endif /* LIBARITH_H */
