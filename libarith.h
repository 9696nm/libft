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

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

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
	float	x;
	float	y;
	float	z;
	float	w;
}	t_quat;

/* q_rsqrt.c */
float		q_rsqrtf(float number);

/* quaternion.c */
t_quat		quat_normalize(t_quat q);
t_quat		quat_multiply(t_quat q1, t_quat q2);
t_quat		quat_conjugate(t_quat q);
t_quat		quat_rotate(t_quat src, t_quat rot);
t_quat		quat_axis_angle(t_vec3 v, float angle);
t_quat		quat_from_to(t_vec3 from, t_vec3 to);

/* vecter3.c */
t_vec3		vec3_normalize(t_vec3 v);
float		vec3_dot(t_vec3 v1, t_vec3 v2);
t_vec3		vec3_cross(t_vec3 from, t_vec3 to);
t_vec3		vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3		vec3_sub(t_vec3 v1, t_vec3 v2);

/* coordinates3.c */
t_coord3	coord_add(t_coord3 c1, t_coord3 c2);
t_coord3	coord_sub(t_coord3 c1, t_coord3 c2);

/* conversion.c */
t_vec3		coord_to_vec3(t_coord3 coord);
t_coord3	vec3_to_coord(t_vec3 vec);

#endif /* LIBARITH_H */
