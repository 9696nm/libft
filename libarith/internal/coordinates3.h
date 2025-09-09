/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates3.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:53:20 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/14 22:20:56 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDINATES3_H
# define COORDINATES3_H

struct						s_vecter3;
typedef struct s_vecter3	t_vec3;

typedef struct s_coordinates3
{
	float	x;
	float	y;
	float	z;
}	t_coord3;

/* coordinates3.c */
t_coord3	coord_add(t_coord3 c1, t_coord3 c2);
t_coord3	coord_sub(t_coord3 c1, t_coord3 c2);

/* conversion.c */
t_coord3	vec3_to_coord(t_vec3 vec);

#endif /* COORDINATES3_H */
