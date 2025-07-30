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
}	t_quater;

/* q_rsqrt.c */
float		q_rsqrtf(float number);

/* quaternion.c */
t_quater	quater_normalize(t_quater q);
t_quater	quater_multiply(t_quater q1, t_quater q2);
t_quater	quater_conjugate(const t_quater q);
t_quater	quater_rotate(t_quater qv, t_quater q);
t_quater	quater_axis_angle(float x, float y, float z, float angle);

#endif /* LIBARITH_H */
