/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:57:13 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/14 22:21:46 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vecter.h"

t_vec3	vecter_normalize(t_vec3 v)
{
	float	norm;

	norm = q_rsqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	v.x *= norm;
	v.y *= norm;
	v.z *= norm;
	return (v);
}
