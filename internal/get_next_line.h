/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:33:31 by hmori             #+#    #+#             */
/*   Updated: 2026/06/21 10:10:28 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <bits/posix1_lim.h>
# include <limits.h>
# include <unistd.h>
# include <stddef.h>
# include <sys/user.h>

# ifndef STASH_LIMIT
#  define STASH_LIMIT 128
# endif

# ifndef MAX_LINE_LENGTH
#  define MAX_LINE_LENGTH SSIZE_MAX
# endif

# ifndef GNL_BUFFER_MAX
#  ifdef __linux__
#   define GNL_BUFFER_MAX (INT_MAX & PAGE_MASK)
#  else
#   define GNL_BUFFER_MAX SSIZE_MAX
#  endif
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef SED_CHARACTER
#  define SED_CHARACTER '\n'
# endif

enum e_gnl_buffer_size_check
{
	GNL_BUFFER_SIZE_MUST_BE_POSITIVE = 1 / (!!(0 < BUFFER_SIZE)),
	GNL_BUFFER_SIZE_MUST_FIT_READ = 1 / (!!((size_t)BUFFER_SIZE
			<= (size_t)GNL_BUFFER_MAX))
};

typedef struct s_byte_array
{
	void	*data;
	ssize_t	len;
	int		fd;
}	t_byte_array;

#endif /* GET_NEXT_LINE_H */
