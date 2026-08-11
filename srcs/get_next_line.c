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

#define _POSIX_C_SOURCE 200809L

#include "internal/get_next_line.h"

#include <unistd.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "ft/string.h"

static t_byte_array	*get_stash(int fd)
{
	static t_byte_array	fd_stash[STASH_LIMIT];
	int					idx;
	int					empty;

	idx = 0;
	empty = -1;
	if (fd < 0 || fd == INT_MAX)
		return (NULL);
	while (idx < STASH_LIMIT)
	{
		if (fd + 1 == fd_stash[idx].fd)
			return (&fd_stash[idx]);
		if (-1 == empty && 0 == fd_stash[idx].fd)
			empty = idx;
		idx++;
	}
	if (-1 == empty)
		return (NULL);
	fd_stash[empty].data = malloc(BUFFER_SIZE);
	if (NULL == fd_stash[empty].data)
		return (NULL);
	fd_stash[empty].fd = fd + 1;
	return (&fd_stash[empty]);
}

static void	re_set_res(t_byte_array *old_res, t_byte_array *st)
{
	t_byte_array	new_res;
	ssize_t			nl_len;

	ft_memset(&new_res, '\0', sizeof(t_byte_array));
	if (NULL == ft_memchr(st->data, SED_CHARACTER, st->len))
		nl_len = st->len;
	else
		nl_len = ft_memchr(st->data, SED_CHARACTER, st->len) - st->data + 1;
	new_res.len = old_res->len + nl_len;
	if (nl_len <= MAX_LINE_LENGTH - old_res->len)
		new_res.data = malloc(sizeof(char) * (new_res.len + 1));
	if (new_res.data)
	{
		((unsigned char *)new_res.data)[new_res.len] = '\0';
		if (old_res->data)
			ft_memmove(new_res.data, old_res->data, old_res->len);
		ft_memmove(new_res.data + old_res->len, st->data, nl_len);
		st->len = st->len - nl_len;
		ft_memmove(st->data, st->data + nl_len, st->len);
	}
	else
		new_res.len = 0;
	free(old_res->data);
	*old_res = new_res;
}

void	*gnl_binary(int fd, ssize_t *data_size)
{
	t_byte_array	*stash;
	t_byte_array	res;
	ssize_t			rlen;

	stash = get_stash(fd);
	ft_memset(&res, '\0', sizeof(t_byte_array));
	while (stash && stash->data)
	{
		rlen = stash->len;
		if (stash->len <= 0)
			rlen = read(fd, stash->data, BUFFER_SIZE);
		stash->len = rlen;
		if (0 < rlen)
			re_set_res(&res, stash);
		if (rlen <= 0 || 0 == res.len)
		{
			free(stash->data);
			ft_memset(stash, '\0', sizeof(t_byte_array));
		}
		if (data_size)
			*data_size = res.len;
		if (res.data && ft_memchr(res.data, SED_CHARACTER, res.len))
			break ;
	}
	return (res.data);
}

char	*get_next_line(int fd)
{
	return ((char *)gnl_binary(fd, NULL));
}
