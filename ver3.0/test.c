#include "libft.h"
#include <stdio.h>

int main()
{
	printf("ft_:%d\nerrno:%d\n", ft_atoi("-2147483649"), errno);
	printf("ord:%d\nerrno:%d\n", atoi("-2147483649"), errno);
	return (0);
}

