/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:57:13 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/14 22:21:46 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordinates3.h"

t_coord3	coord_add(t_coord3 c1, t_coord3 c2)
{
	t_coord3	result;

	result.x = c1.x + c2.x;
	result.y = c1.y + c2.y;
	result.z = c1.z + c2.z;
	return (result);
}
