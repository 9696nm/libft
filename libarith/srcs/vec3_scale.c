/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:00:00 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/09/09 12:00:00 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vecter3.h"

t_vec3	vec3_scale(t_vec3 v, float scale)
{
	t_vec3	result;

	result.x = v.x * scale;
	result.y = v.y * scale;
	result.z = v.z * scale;
	return (result);
}
