/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_conjugate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:57:13 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/14 22:21:46 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

// Set up conjugate quaternions.
t_quat	quat_conjugate(t_quat q)
{
	t_quat	q_conj;

	q_conj.w = q.w;
	q_conj.x = -q.x;
	q_conj.y = -q.y;
	q_conj.z = -q.z;
	return (q_conj);
}
