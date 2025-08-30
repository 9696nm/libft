/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:53:20 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/14 22:20:56 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUATERNION_H
# define QUATERNION_H

# include <math.h>
# include "q_rsqrt.h"

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

/* quaternion.c */
t_quat	quat_normalize(t_quat q);
t_quat	quat_multiply(t_quat q1, t_quat q2);
t_quat	quat_conjugate(const t_quat q);
t_quat	quat_rotate(t_quat qv, t_quat q);
t_quat	quat_axis_angle(float x, float y, float z, float angle);

#endif /* QUATERNION_H */
