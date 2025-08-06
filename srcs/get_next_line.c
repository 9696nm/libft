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

#include "ft/stdlib.h"
#include "ft/string.h"
#include "get_next_line.h"

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

static void	resbuf_remove(ssize_t len, char *result, t_gnl_node *node)
{
	if (node == NULL)
		return ;
	resbuf_remove(len, result, node->next);
	if (result)
		ft_strlcat(result, node->element, len + 1);
	free(node);
}

static t_gnl_node	*resbuf_add(t_gnl_buf buf)
{
	t_gnl_node	*new;
	char		*trimmed;

	new = malloc(sizeof(t_gnl_node));
	if (new)
	{
		new->next = buf.res;
		trimmed = ft_strchr(buf.pull, '\n');
		if (trimmed)
			ft_strlcpy(new->element, buf.pull, trimmed - buf.pull + 2);
		else
			ft_strlcpy(new->element, buf.pull, BUFFER_SIZE + 1);
	}
	else
		resbuf_remove(0, NULL, buf.res);
	return (new);
}

static char	*resbuf_cat(t_gnl_node *node)
{
	t_gnl_node	*tmp;
	ssize_t		len;
	char		*result;

	tmp = node;
	len = 0;
	result = NULL;
	while (tmp)
	{
		len += ft_strlen(tmp->element);
		tmp = tmp->next;
	}
	if (len)
		result = ft_calloc(sizeof(char), (len + 1));
	resbuf_remove(len, result, node);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*memrys[FD_MAX];
	t_gnl_buf	buf;

	buf.res = NULL;
	while (0 <= fd && fd < FD_MAX && memry_alloc(&memrys[fd]))
	{
		ft_bzero(buf.pull, BUFFER_SIZE + 1);
		if (*memrys[fd] == '\0')
			buf.rlen = read(fd, buf.pull, BUFFER_SIZE);
		else
			buf.rlen = ft_strlcpy(buf.pull, memrys[fd], BUFFER_SIZE + 1);
		if (BUFFER_SIZE == 0 || buf.rlen < 0)
			break ;
		if (ft_strchr(buf.pull, '\n'))
			ft_strlcpy(memrys[fd], ft_strchr(buf.pull, '\n') + 1, buf.rlen + 1);
		else
			ft_bzero(memrys[fd], BUFFER_SIZE + 1);
		buf.res = resbuf_add(buf);
		if (buf.res == NULL)
			return (NULL);
		if (ft_strchr(buf.res->element, '\n') || buf.rlen == 0)
			return (resbuf_cat(buf.res));
	}
	resbuf_remove(0, NULL, buf.res);
	return (NULL);
}

// __attribute__((destructor)) static void	gnl_global_free(void)
// {
// 	int	fd;

// 	fd = 0;
// 	while (fd <= FD_MAX)
// 	{
// 		if (gnl_memrys[fd])
// 			free(gnl_memrys[fd]);
// 		fd++;
// 	}
// }

// #include <stdio.h>
// #include <fcntl.h>
// int	main (int argc, char *argv[])
// {
// 	char	*str;

// 	if (argc != 2)
// 		return (0);
// 	int	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 		return (0);
// 	while (str = get_next_line(fd), str)
// 	{
// 		printf("%s", str);
// 		fflush(stdout);
// 		free(str);
// 	}
// 	// printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
// 	close(fd);
// 	return (0);
// }
