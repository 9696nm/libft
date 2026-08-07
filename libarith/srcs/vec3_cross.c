/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:57:13 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/14 22:21:46 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vecter3.h"

t_vec3	vec3_cross(t_vec3 from, t_vec3 to)
{
	t_vec3	result;

	result.x = -(from.y * to.z - from.z * to.y);
	result.y = -(from.z * to.x - from.x * to.z);
	result.z = -(from.x * to.y - from.y * to.x);
	return (result);
}
