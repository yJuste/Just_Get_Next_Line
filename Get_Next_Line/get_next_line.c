/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated: 2024/11/10 15:16:43 by jlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*str_join(char *s1, char *s2, int len)
{
	char	*new_str;
	int		s1_len = 0;

	if (s1)
		s1_len = ft_strlen(s1);
	new_str = malloc(s1_len + len + 1);
	if (!new_str)
		return (NULL);
	if (s1)
		ft_memcpy(new_str, s1, s1_len);
	ft_memcpy(new_str + s1_len, s2, len);
	new_str[s1_len + len] = '\0';
	if (s1)
		free(s1);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buf_read;
	static int	buf_pos;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buf_pos >= buf_read)
		{
			buf_read = read(fd, buffer, BUFFER_SIZE);
			buf_pos = 0;
			if (buf_read <= 0)
				break ;
		}
		if (buffer[buf_pos] == '\n')
		{
			line = str_join(line, buffer + buf_pos, 1);
			buf_pos++;
			return (line);
		}
		line = str_join(line, buffer + buf_pos, 1);
		buf_pos++;
	}
	return (line);
}
