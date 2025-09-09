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

# include "vecter3.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define EPSILON 1e-6f

typedef struct s_quaternion
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_quat;

/* quaternion.c */
t_quat	quat_normalize(t_quat q);
t_quat	quat_multiply(t_quat q1, t_quat q2);
t_quat	quat_conjugate(t_quat q);
t_quat	quat_rotate(t_quat src, t_quat rot);
t_quat	quat_axis_angle(t_vec3 v, float angle);
t_quat	quat_from_to(t_vec3 from, t_vec3 to);

#endif /* QUATERNION_H */
