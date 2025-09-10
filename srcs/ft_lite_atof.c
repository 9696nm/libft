/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lite_atof.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 00:00:00 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/27 00:00:00 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ctype.h"

static const char	*skip_whitespace(const char *str)
{
	while (ft_isspace(*str))
		str++;
	return (str);
}

static int	parse_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (sign);
}

static double	parse_integer_part(const char **str)
{
	double	result;

	result = 0.0;
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10.0 + (**str - '0');
		(*str)++;
	}
	return (result);
}

static double	parse_decimal_part(const char **str)
{
	double	result;
	double	fraction;

	result = 0.0;
	fraction = 0.1;
	if (**str == '.')
	{
		(*str)++;
		while (**str >= '0' && **str <= '9')
		{
			result += (**str - '0') * fraction;
			fraction *= 0.1;
			(*str)++;
		}
	}
	return (result);
}

double	ft_lite_atof(const char *str)
{
	int		sign;
	double	integer_part;
	double	decimal_part;

	if (!str)
		return (0.0);
	str = skip_whitespace(str);
	sign = parse_sign(&str);
	integer_part = parse_integer_part(&str);
	decimal_part = parse_decimal_part(&str);
	return ((integer_part + decimal_part) * sign);
}
