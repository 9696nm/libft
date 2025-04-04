
#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int	main(int argc, char *argv[])
{
	char	*nptr;
	char	*endptr;
	int		base;
	long	nbr;
	int		errnbr;

	if (argc != 4)
		return (ft_putstr_fd("ArgumentError\n", STDERR_FILENO), 1);
	nptr = argv[1];
	endptr = argv[2];
	base = atoi(argv[3]);

	errno = 0;
	if (argv[2])
		nbr = strtol(nptr, &endptr, base);
	else
		nbr = strtol(nptr, NULL, base);
	errnbr = errno;
	printf("ret[%5li] endptr[%-10s] errno[%2i]\n", nbr, endptr, errnbr);
	return (0);
}