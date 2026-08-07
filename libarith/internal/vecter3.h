/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecter3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:53:20 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/14 22:20:56 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTER3_H
# define VECTER3_H

struct							s_coordinates3;
typedef struct s_coordinates3	t_coord3;

typedef struct s_vecter3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

/* vecter3.c */
t_vec3		vec3_normalize(t_vec3 v);
float		vec3_dot(t_vec3 v1, t_vec3 v2);
t_vec3		vec3_cross(t_vec3 from, t_vec3 to);
t_vec3		vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3		vec3_sub(t_vec3 v1, t_vec3 v2);

/* conversion.c */
t_vec3		coord_to_vec3(t_coord3 coord);

#endif /* VECTER3_H */
