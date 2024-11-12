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

# ifndef FD_MAX
#  define FD_MAX 500
# endif

// get_next_line.c

char	*get_next_line(int fd);
char	*ft_free(char *buffer, char *buf);

// get_next_line_utils.c

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_calloc(size_t count, size_t size);

#endif
