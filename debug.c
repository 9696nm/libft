
#include "libft.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

static char	*endptr;
static long	nbr;
static int	errnbr;

#define STRTOL_TEST(nptr, base) \
{ \
	errno = 0; \
	endptr = "ab"; \
	nbr = strtol(nptr, &endptr, base); \
	errnbr = errno; \
	printf("strtol    -> ret[%5li] endptr[%-10s] errno[%2i]\n", nbr, endptr, errnbr); \
\
	errno = 0; \
	endptr = "ab"; \
	nbr = ft_strtol(nptr, &endptr, base); \
	errnbr = errno; \
	printf("ft_strtol -> ret[%5li] endptr[%-10s] errno[%2i]\n", nbr, endptr, errnbr); \
}

int	main(void)
{
	/* sccucce pattern */
	// STRTOL_TEST("42", -1);
	// STRTOL_TEST("42", 0);
	// STRTOL_TEST("42", 1);
	// STRTOL_TEST("42", 2);
	// STRTOL_TEST("42", 36);
	// STRTOL_TEST("42", 37);
	// STRTOL_TEST("  0x7FFFFFFFFFFFFFFF", 0);
	// STRTOL_TEST("  0x8000000000000000", 0);
	// STRTOL_TEST("  -0x8000000000000000", 0);
	// STRTOL_TEST("  -0x8000000000000001", 0);
	// STRTOL_TEST("  -0x800000000000000100", 0);
	// STRTOL_TEST("  92233720368547758070000", 0);

	// STRTOL_TEST("  -42abc", 0);
	STRTOL_TEST("  +0x9999999999999999i0p42abzc", 0);

	/* error pattern */
	// STRTOL_TEST("  +a042abc", 0);
	// STRTOL_TEST("  +0", 0);
	// STRTOL_TEST("  +0", 0);
	// STRTOL_TEST("  +42abc", -1);
	// STRTOL_TEST("  +-42abc", 0);
	// STRTOL_TEST("  +0x255", 8);
	return (0);
}
