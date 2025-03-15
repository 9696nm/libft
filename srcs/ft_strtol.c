/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:12:06 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/03/15 14:12:08 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static int	checkliteral(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (ft_memcmp(str, "0", 1) == 0 && -1 < isbasedigit(*(str + 1), 8))
		return (8);
	if (ft_memcmp(str, "0x", 2) == 0 && -1 < isbasedigit(*(str + 2), 16))
		return (16);
	if (ft_memcmp(str, "0X", 2) == 0 && -1 < isbasedigit(*(str + 2), 16))
		return (16);
	return (10);
}

static int	sizeliteral(char *str, int base)
{
	int	len;

	len = 0;
	if (str[len] == '-' || str[len] == '+')
		len++;
	if (ft_memcmp(str + len, "0", 1) == 0 && base == 8)
		len += 1;
	if (ft_memcmp(str + len, "0x", 1) == 0 && base == 16)
		len += 2;
	if (ft_memcmp(str + len, "0X", 1) == 0 && base == 16)
		len += 2;
	if (-1 < isbasedigit(str[len], base))
		return (len);
	return (0);
}

static long	basetoint(char *str, int base)
{
	int			sing;
	long int	nbr;

	nbr = 0;
	sing = 1;
	if (*str == '-')
		sing = -1;
	str += sizeliteral(str, base);
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

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	long int	nbr;
	char		*str;

	str = (char *)nptr;
	while (ft_isspace(*str))
		str++;
	if (base == 0)
		base = checkliteral(str);
	if (2 <= base && base <= 36)
		nbr = basetoint(str, base);
	else
	{
		errno = EINVAL;
		return (0);
	}
	str += sizeliteral(str, base);
	while (-1 < isbasedigit(*str, base))
		str++;
	*endptr = str;
	return (nbr);
}

#include "stdio.h"
#include "stdlib.h"

#define TEST(nptr, base) \
{ \
	char	*endptr; \
	long	nbr; \
	int		errnbr; \
	nbr = strtol(nptr, &endptr, base); \
	errnbr = errno; \
	printf("strtol    -> ret[%5li] endptr[%-8s] errno[%2i]\n", nbr, endptr, errnbr); \
	errno = 0; \
	nbr = ft_strtol(nptr, &endptr, base); \
	errnbr = errno; \
	printf("ft_strtol -> ret[%5li] endptr[%-8s] errno[%2i]\n", nbr, endptr, errnbr); \
}

int	main(void)
{
	TEST("    +100101110", 2);

	/* error pattern */
	// TEST("    +0x255", 8);
	return (0);

}