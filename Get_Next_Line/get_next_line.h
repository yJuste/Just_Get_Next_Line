/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// Standard Libraries

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

// Buffers

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 60
# endif

# ifndef LINE_SIZE
#  define LINE_SIZE 70000
# endif

# ifndef FD_MAX
#  define FD_MAX 500
# endif

// get_next_line.c

char	*get_next_line(int fd);

// get_next_line_utils.c

char	*ft_strdup(const char *s1);

#endif
