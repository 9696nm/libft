/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:57:13 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/14 22:21:46 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "q_rsqrt.h"
#include "vecter3.h"

t_vec3	vec3_normalize(t_vec3 v)
{
	float	norm;

	norm = q_rsqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	v.x *= norm;
	v.y *= norm;
	v.z *= norm;
	return (v);
}
