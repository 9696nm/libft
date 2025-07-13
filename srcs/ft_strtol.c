/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:12:06 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/06/23 21:45:03 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdbool.h>
#include <limits.h>

#include "ft/ctype.h"

static int	checkliteral(const char **str, int base)
{
	if (**str == '-' || **str == '+')
		*str++;
	if (**str == '0')
	{
		if ((base == 0 || base == 2) && ft_toupper((*str)[1]) == 'B')
		{
			(*str) += 2;
			return (2);
		}
		if ((base == 0 || base == 16) && ft_toupper((*str)[1]) == 'B')
		{
			(*str) += 2;
			return (16);
		}
		if (base == 0)
			return (8);
	}
	else if (base == 0)
		return (10);
	return (base);
}

static int	isbasedigit(int c, int base)
{
	if ('0' <= c && c <= ('0' + base - 1) && c <= '9')
		return (c - '0');
	if ('a' <= c && c <= ('a' + base - 11))
		return (c - 'a' + 10);
	if ('A' <= c && c <= ('A' + base - 11))
		return (c - 'A' + 10);
	return (-1);
}

static long	basetoint(const char *str, int base, int sing)
{
	long int	nbr;

	nbr = 0;
	while (-1 < isbasedigit(*str, base))
	{
		nbr = nbr * base + (sing * isbasedigit(*str, base));
		if ((sing == 1 && nbr < 0) || (sing == -1 && 0 < nbr))
			errno = ERANGE;
		if (sing == 1 && nbr < 0)
			return (LONG_MAX);
		if (sing == -1 && 0 < nbr)
			return (LONG_MIN);
		str++;
	}
	return (nbr);
}

long	__ft_strtol(const char *restrict nptr, char **restrict endptr,
			int base, bool bin_cst)
{
	long int	nbr;
	int			sing;

	if (base < 0 || base == 1 || 36 < base)
	{
		errno = EINVAL;
		return (0L);
	}
	*endptr = (char *)nptr;
	while (ft_isspace(*nptr))
		nptr++;
	sing = 1;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sing = -1;
	base = checkliteral(&nptr, base);
	if (ft_isdigit(*nptr) == 0)
		nbr = basetoint(nptr, base, sing);
	*endptr = (char *)nptr;
	return (nbr);
}

long	ft_strtol(const char *restrict nptr, char **restrict endptr, int base)
{
	return (__ft_strtol(nptr, endptr, base, false));
}
