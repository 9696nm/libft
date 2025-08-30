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

#ifndef VECTER_H
# define VECTER_H

# include "q_rsqrt.h"

typedef struct s_vecter3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

/* vecter.c */
t_vec3	vecter3_normalize(t_vec3 v);

#endif /* VECTER_H */