/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:58:22 by hmori             #+#    #+#             */
/*   Updated: 2025/02/22 18:29:51 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/select.h>

#include "get_next_line.h"

static char	*na_strchr(const char *source, int c)
{
	while (*source)
	{
		if (*source == (unsigned char)c)
			return ((char *)source);
		source++;
	}
	return ((char *)source);
}

static char	*rescopy(t_mem lst, char **oldres)
{
	char	*joint;

	joint = ft_strchr(lst.pull, '\n');
	if (joint)
		lst.pull[joint - lst.pull + 1] = '\0';
	joint = ft_strjoin(*oldres, lst.pull);
	free(*oldres);
	return (joint);
}

#include <stdio.h>
static int	memry_alloc(char **memry)
{
	char	*str;

	if (*memry == NULL)
		str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	else
		return (true);
	if (str == NULL)
		return (false);
	ft_bzero(str, BUFFER_SIZE + 1);
	*memry = str;
	return (true);
}

char	*get_next_line(int fd)
{
	static char	*memrys[FD_MAX];
	t_gnl_buf	lst;

	// lst.result = malloc(sizeof(char));
	// *lst.result = '\0';
	lst.result = NULL;
	lst.read_len = BUFFER_SIZE;
	while (lst.read_len && 0 <= fd && fd < FD_MAX && memry_alloc(&memrys[fd]))
	{
		ft_bzero(lst.pull, BUFFER_SIZE + 1);
		if (*memrys[fd] == '\0')
			lst.read_len = read(fd, lst.pull, BUFFER_SIZE);
		else
			ft_strlcpy(lst.pull, memrys[fd] + 1, ft_strlen(memrys[fd]) + 1);
		if (lst.read_len < 0 || lst.pull == NULL)
			break ;
		ft_strlcpy(memrys[fd], na_strchr(lst.pull, '\n'), lst.read_len + 1);
		lst.result = rescopy(lst, &(lst.result));
		if (*memrys[fd] == '\n' || (*lst.result && lst.read_len == 0))
			return (lst.result);
	}
	if (lst.result)
		free(lst.result);
	return (NULL);
}

// __attribute__((destructor)) static void	global_free(void)
// {
// 	int	fd;

// 	fd = 0;
// 	while (fd <= FD_MAX)
// 	{
// 		if (memrys[fd])
// 			free(memrys[fd]);
// 		fd++;
// 	}
// }

#include <stdio.h>
#include <fcntl.h>
int	main (int argc, char *argv[])
{
	char	*str;

	if (argc != 2)
		return (0);
	int	fd = open(argv[1], O_RDONLY);
	while (str = get_next_line(fd), str)
		printf("%s", str);
		// continue ;
	printf("%d\n", BUFFER_SIZE);
	free(str);
	close(fd);
	return (0);
}
