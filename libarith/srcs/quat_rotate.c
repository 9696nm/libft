/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:57:13 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/14 22:21:46 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

// Rotation of 3D vectors by quaternions.
t_quat	quat_rotate(t_quat src, t_quat rot)
{
	t_quat	q_conj;
	t_quat	result;

	q_conj = quat_conjugate(rot);
	result = quat_multiply(quat_multiply(q_conj, src), rot);
	return (result);
}
