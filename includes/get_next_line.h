/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:33:31 by hmori             #+#    #+#             */
/*   Updated: 2025/02/22 18:29:43 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/select.h>

# include "libft.h"

# ifndef FD_MAX
#  define FD_MAX FD_SETSIZE
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# if BUFFER_SIZE < 0
# error "BUFFER_SIZE must be a positive number"
# endif

# if 65536 < BUFFER_SIZE
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 65536
# endif

typedef struct s_mem
{
	ssize_t	read_len;
	char	*result;
	char	pull[BUFFER_SIZE + 1];
}	t_mem;

char	*get_next_line(int fd);

#endif

// # include <limits.h> //PIPE_BUF

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE PIPE_BUF
// # endif

// # if (PIPE_DEF_BUFFERS * PIPE_BUF) < BUFFER_SIZE
// #  undef BUFFER_SIZE
// #  define BUFFER_SIZE (PIPE_DEF_BUFFERS * PIPE_BUF)
// # endif
