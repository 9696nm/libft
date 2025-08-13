/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 12:51:15 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/09 12:51:16 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	lite_atof(char *str)
{
	;
}

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include "ft/stdio.h"

typedef union u_cast
{
	float		f;
	struct ieee_float
	{
		uint32_t	mantissa : 23;
		uint8_t		exponent : 8;
		uint8_t		sign : 1;
	}	bits;
}	t_cast;

int	main(void)
{
	t_cast	num;

	num.f = FLT_MAX;
	// num.d = atof("");
	// num.d = atof(" 12");
	// bzero(&num.d, 8);
	// num.d = 0;
	// num.d = 1.7976931348623159e+308;
	// num.d = NAN;

	print_bits(&num.f, sizeof(num.f));
	printf("f:%f\n", num.f);
	printf("u:%u\n", (unsigned)num.bits.mantissa);
	printf("-> %d\n", (num.f == NAN));
	return (0);
}
