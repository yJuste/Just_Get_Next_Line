/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// Standard Libraries

# include <stdlib.h>
# include <unistd.h>

// Buffers

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 60
# endif

# ifndef FD_MAX
#  define FD_MAX 500
# endif

// Structure

typedef struct s_buf
{
	char	buffer[BUFFER_SIZE];
	int		buf_read;
	int		buf_pos;
}	t_buf;

// get_next_line_bonus.c

char	*get_next_line(int fd);

// get_next_line_utils_bonus.c

char	*ft_strdup(const char *s1);

#endif
